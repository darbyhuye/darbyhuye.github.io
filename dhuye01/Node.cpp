//
//  Node.cpp
//  trie
//
//  Created by Chris Gregg on 3/29/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//
//  [MAS 2015-10-17] Included iostream.h explicitly and put using
//                   statement in.
//

#include <iostream>

#include "Node.h"

using namespace std;

/*
 * Default constructor makes an empty Trie.  Recall that, even in an
 *  empty trie, we do have a node.  The root node has a blank as the
 * character and a false wordMarker.
 */
Node::Node()
{
	theCharacter = ' '; 
	wordMarker   = false; 

	for (int i = 0; i < ALPHABET_LENGTH; i++)
                children[i] = NULL;
}

void Node::appendChild(Node *child)
{
	char c = child->theCharacter;
	if(children[c - 'a'] != NULL)
		return;
	else
		children[c - 'a'] = child;
}

Node *Node::findChild(char c)
{
	return children[c - 'a'];
}

void Node::printNode(int level)
{
        cout << level << "," << theCharacter << "," << wordMarker << endl;
        for (int i = 0; i < ALPHABET_LENGTH; i++) {
                Node *tmp = children[i];
                if (tmp != NULL) {
                	tmp->printNode(level + 1);
                }
        }
}

/*
 * You can ignore this code.  It has to do with interactions with the
 * web interface.
 */
size_t Node::addPreNodes(vector <preNode> preNodes, int level, size_t index)
{
	while (index != preNodes.size()) {           // base case
		preNode pn = preNodes[index];
		//cout << level << "," << pn.level << "," 
                //     << pn.c << "," << pn.wordMarker << "\n";
		if (pn.level <= level)
                        return index;                // next sibling

		// we have a child to add
		Node *tmp = new Node();
		tmp->setCharacter(pn.c);
		if (pn.wordMarker)
                        tmp->setWordMarker();
		appendChild(tmp);
		index = tmp->addPreNodes(preNodes, pn.level, index + 1);
	}
	return index;
}
