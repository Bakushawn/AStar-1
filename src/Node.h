#include <vector>

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	Node(double, double);
	~Node();
	bool addConnection(Node*);
	bool removeConnection(Node*);

	double computeCost(const Node*, const Node*);

	void setParent(Node*);
	void removeParent();
	Node* getParent();

	std::vector<Node*> getConnections();
	auto begin();

	double _x, _y;
private:
	std::vector<Node*> _connections;
	Node* _parent;
};

#endif /* NODE_H_ */
