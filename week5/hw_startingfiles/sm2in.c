/** ex 9.4 - modify shsh1.c to accept multiple arguments
  smsh1.c  small-shell version 1
 **		first really useful version after prompting shell
 **		this one parses the command line into strings
 **		uses fork, exec, wait, and ignores signals
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "smsh.h"
#include "execute.c"

#define	DFL_PROMPT	"> "

int count_commands(char** commands){
	int count;
	char** cmd = commands;

	count = 0;
	while(*cmd != NULL){
		count++;
		cmd++;
	}
	return count;
}


/* splitline.c - commmand reading and parsing functions for smsh
 *    
 *    char *next_cmd(char *prompt, FILE *fp) - get next command
 *    char **splitline(char *str);           - parse a string
 */




char * next_cmd(char *prompt, FILE *fp)
/*
 * purpose: read next command line from fp
 * returns: dynamically allocated string holding command line
 *  errors: NULL at EOF (not really an error)
 *          calls fatal from emalloc()
 *   notes: allocates space in BUFSIZ chunks.  
 */
{
	 char	*buf = NULL; 				/* the buffer		*/
	 int	bufspace = 0;			/* total size		*/
	 int	pos = 0;			/* current position	*/
 	 int	c;				/* input char		*/
	
	//new variable to store number of commands and array of pointer (double pointer char) to store the commands
	/*int command_count = 0;
	char** commands = NULL;	*/


	 printf("%s", prompt);				/* prompt user	*/
	 while( ( c = getc(fp)) != EOF ) { /* need space? */
		 if( pos+1 >= bufspace ){		/* 1 for \0	*/
			if ( bufspace == 0 )		/* y: 1st time	*/
				buf = emalloc(BUFSIZ);
     			 else				/* or expand	*/
				buf = erealloc(buf,bufspace+BUFSIZ);
			
			bufspace += BUFSIZ;	/* update size	*/
			    	
		}

		/* end of command? */
		if ( c == '\n' )
			break;
					
		/* no, add to buffer */
		buf[pos++] = c;
		
		if ( c == EOF && pos == 0 ){		/* EOF and no input	*/
			return NULL;	
		}					/* say so		*/
		buf[pos] = '\0';
		return buf;
}

/**
 **	splitline ( parse a line into an array of strings )
 **/
#define	is_delim(x) ((x)==' '||(x)=='\t')

//need to add a a function to split the line into arguments with a seperator (maybe ':'?)

char ** splitline(char *line)
/*
 * purpose: split a line into array of white-space separated tokens
 * returns: a NULL-terminated array of pointers to copies of the tokens
 *          or NULL if line if no tokens on the line
 *  action: traverse the array, locate strings, make copies
 *    note: strtok() could work, but we may want to add quotes later
 */
{
  char	*newstr();
  char	**args ;
  int	spots = 0;			/* spots in table	*/
  int	bufspace = 0;			/* bytes in table	*/
  int	argnum = 0;			/* slots used		*/
  char	*cp = line;			/* pos in string	*/
  char	*start;
  int	len;

  if ( line == NULL )			/* handle special case	*/
    return NULL;

  args     = emalloc(BUFSIZ);		/* initialize array	*/
  bufspace = BUFSIZ;
  spots    = BUFSIZ/sizeof(char *);

  while( *cp != '\0' )
    {
      while ( is_delim(*cp) )		/* skip leading spaces	*/
	cp++;
      if ( *cp == '\0' )		/* quit at end-o-string	*/
	break;

      /* make sure the array has room (+1 for NULL) */
      if ( argnum+1 >= spots ){
	args = erealloc(args,bufspace+BUFSIZ);
	bufspace += BUFSIZ;
	spots += (BUFSIZ/sizeof(char *));
      }

      /* mark start, then find end of word */
      start = cp;
      len   = 1;
      while (*++cp != '\0' && !(is_delim(*cp)) )
	len++;
      args[argnum++] = newstr(start, len);
    }
  args[argnum] = NULL;
  return args;
}

/*
 * purpose: constructor for strings
 * returns: a string, never NULL
 */
char *newstr(char *s, int l)
{
  char *rv = emalloc(l+1);

  rv[l] = '\0';
  strncpy(rv, s, l);
  return rv;
}

void freelist(char **list)
/*
 * purpose: free the list returned by splitline
 * returns: nothing
 *  action: free all strings in list and then free the list
 */
{
  char	**cp = list;
  while( *cp )
    free(*cp++);
  free(list);
}

void * emalloc(size_t n)
{
  void *rv ;
  if ( (rv = malloc(n)) == NULL )
    fatal("out of memory","",1);
  return rv;
}

void * erealloc(void *p, size_t n)
{
  void *rv;
  if ( (rv = realloc(p,n)) == NULL )
    fatal("realloc() failed","",1);
  return rv;
}


void setup()
/*
 * purpose: initialize shell
 * returns: nothing. calls fatal() if trouble
 */
{
  signal(SIGINT,  SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
}

void fatal(char *s1, char *s2, int n)
{
  fprintf(stderr,"Error: %s,%s\n", s1, s2);
  exit(n);
}

int main()
{
  char	*cmdline, *prompt, **arglist;
  int	result;
  void	setup();

  prompt = DFL_PROMPT;
  setup();

  while ( (cmdline = next_cmd(prompt, stdin)) != NULL ){
    if ( (arglist = splitline(cmdline)) != NULL  ){
        result = execute(arglist);
        freelist(arglist);
    }
    free(cmdline);
  }
  return 0;
}
