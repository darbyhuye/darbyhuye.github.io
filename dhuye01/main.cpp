#include <iostream>
#include <string>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>

#include "Trie.h"
#include "cgiBackend.h"

using namespace std;

static const int      MAX_USER_NAME_LENGTH = 50;
static const unsigned TIMEOUT              =  5;  /* 5 seconds */

void ensureCorrectUsage(int argc, char *argv[]);
void setTimeout(unsigned seconds);
void alarm_callback_handler(int signum);

/*
 * Test program for the Trie lab.
 */
int main(int argc, char *argv[])
{
        ensureCorrectUsage(argc, argv);

        /* Now that we know we have the right number of arguments: */
	string word        = argv[1];
	string function    = argv[2];
	string currentTrie = argv[3];

        /* Ensure trie string ends in new line */
	if (currentTrie[currentTrie.size() - 1] != '\n') {
		currentTrie = currentTrie + "\n";
	}

       setTimeout(TIMEOUT);
	
        Trie *trie = new Trie();
        //functionAndWord f;

        copyToTrie(currentTrie, trie);

        // Send HTTP header
	cout << "Content Type: text/plain\n" << endl;
        if (function == "addWord") {
        	trie->addWord(word);
        	trie->printTrie();
           // string nextword;
           // while(cin >> nextword)
           // {
            //    trie->addWord(nextword);
           //     trie->printTrie();
           // }
        } else if (function == "searchWord") {
        	if (trie->searchWord(word)) {
        		cout << "Found " << word << "\n";
        	} else {
        		cout << "Did not find " << word << "\n";
        	}
        }
        delete trie;

        return 0;
}

/*
 * Make sure the program was called correctly.
 * This program is intended to be called as a result of a web page 
 * operation.  
 * We'll just check that we go the right number of arguments.  For the
 * record:
 *
 * Usage:  trie/trie_web word function currentTrie
 * where:  word        is the word to be added or searched for
 *         function    is either "addWord" or "searchWord"
 *         currentTrie is a string representation of the current Trie
 */ 
void ensureCorrectUsage(int argc, char *argv[])
{
        if (argc != 4) {
		char username[MAX_USER_NAME_LENGTH];
		getlogin_r(username, MAX_USER_NAME_LENGTH);

		cout << "\nThis is a backend program for a web page.\n";
		cout << "\nTo test your program, ";
		cout << "open Firefox and go to the following web page:\n";
		cout << "\nhttp://www.cs.tufts.edu/~";
		cout << username << "/lab9/trie.html\n\n";

		exit(-1);
	}
        (void) argv;  /* Should really validate arguments some day */
}

/*
 * Set up an alarm:  If the program has not completed in this amount
 * of time, then there's probably an infinite loop.
 */
void setTimeout(unsigned seconds)
{
        
	signal(SIGALRM, alarm_callback_handler); /* Install alarm handler */
	alarm(seconds);                          /* Start the clock       */

}

/*
 * This function will be called if the process receives an alarm
 * signal.  If this happens, then we have timed out, presumably due to
 * an infinite loop.
 *
 * Print a message to standard output that will show up in the
 * generated web page, and exit.
 */
void alarm_callback_handler(int signum)
{
   cout << "Content Type: text/plain\n";
   cout << "Program terminated.\n";
   // Cleanup and close up stuff here
   // Terminate program
   exit(signum);
}
