#include <iostream>
#include "graphedge.h"
#include "graphnode.h"

using namespace std;

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode() {}
// {
//     //// STUDENT CO//     /

// //     delete _chot; 

//     ////
// //     //// EOF STUDENT CODE
// }

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(unique_ptr<GraphEdge> edge) //modified
{
    _childEdges.push_back(move(edge)); //modified
}

//// STUDENT CODE (done)
////
void GraphNode::MoveChatbotHere(ChatBot &&chatBot)
{
    //cout << endl;

    ChatBot *chatBotHeap = new ChatBot(move(chatBot));
    _chatBot = move(*chatBotHeap);
    delete chatBotHeap;
//     _chatBot = chatbot;
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(move(_chatBot));
//    _chatBot = nullptr; // invalidate pointer at source
}

////
//// EOF STUDENT CODE (done)

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}