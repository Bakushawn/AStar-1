#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#include "Node.h"

/*
Our Map

	2   5 - 8
	  \ |   |
	1 - 4   7
	|     \ |
    0 - 3 - 6
 */

int SOURCE = 3;
int DESTINATION = 2;

Node* findPath(Node*, Node*);

int main() {
	std::vector<Node*> nodeList;
	for(int y = 1; y <= 3; y++){
		for(int x = 1; x <= 3; x++){
			nodeList.push_back(new Node(x, y));
		}
	}

	nodeList[0]->addConnection(nodeList[1]);
	nodeList[0]->addConnection(nodeList[3]);
	nodeList[1]->addConnection(nodeList[4]);
	nodeList[2]->addConnection(nodeList[4]);
	nodeList[3]->addConnection(nodeList[6]);
	nodeList[4]->addConnection(nodeList[5]);
	nodeList[4]->addConnection(nodeList[6]);
	nodeList[5]->addConnection(nodeList[8]);
	nodeList[6]->addConnection(nodeList[7]);
	nodeList[7]->addConnection(nodeList[8]);

	Node* destination = findPath(nodeList[SOURCE], nodeList[DESTINATION]);

	while(destination){
		std::cout << destination->_x << " " << destination->_y << std::endl;
		destination = destination->getParent();
	}
}

Node* findPath(Node* source, Node* target){
	std::set<std::pair<double, Node*> > openList;
	std::vector<Node*> closedList;

	openList.insert(std::make_pair<double, Node*&>(0, source));

	Node* currentNode;

	while(!openList.empty()){
		currentNode = openList.begin()->second;

		if(currentNode == target){
			return currentNode;
		}

		openList.erase(openList.begin());
		closedList.push_back(currentNode);

		for(auto connection : currentNode->getConnections()){
			auto closedIterator = std::find(closedList.begin(), closedList.end(), connection);
			if(closedIterator != closedList.end()){
				continue;
			}

			connection->setParent(currentNode);
			openList.insert(std::make_pair<double, Node*&>(connection->computeCost(currentNode, target), connection));
		}
	}

	return NULL;
}
