//
//  Trie.cpp
//  trie
//
//  Created by Chris Gregg on 3/29/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//
//  [MAS 2015-10-17] Included string.h explicitly and put 
//                   using statement in.  Also cleaned up formatting.
//

#include <string>

#include "Trie.h"

using namespace std;

Trie::Trie()
{
        root = new Node();
}

Trie::~Trie()
{
        // Free memory
}

void Trie::addWord(string s)
{
      Node *temp = root;

      for ( size_t i = 0; i < s.length(); i++)
      {
      	//if the child of the index i is NULL
      	if(!temp->findChild(s[i]))
      	{
      		//add the rest of the chars as children
      		Node *child = new Node;
      		child->setCharacter(s[i]);
      		temp->appendChild(child);
      	}
     	//iterates down the word 
    	temp = temp->findChild(s[i]);
      }
      temp->setWordMarker();
}


bool Trie::searchWord(string s)
{
	Node *temp = root;
    for(size_t i = 0; i < s.length(); i++)
    {
    	//if the child of the index i is null
    	if(!temp->findChild(s[i]))
    		return false;
    	temp = temp->findChild(s[i]);
    }
    return temp->getWordMarker();

}

void Trie::printTrie()
{
        root->printNode(0);
}

void Trie::addPreNodes(vector<preNode> preNodes)
{
	root->addPreNodes(preNodes, 0, 1);
}
