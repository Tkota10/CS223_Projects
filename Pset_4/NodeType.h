/*
 * Name of File: NodeType.h
 * Creator: Tarun Kota
 * Class: CPSC 223
 * Date: 04/05/23
 * Purpose: This defines the Node that contains the station info, that can then
 * be used to build our Station LinkedList.
 */

#include "Station.h"
using namespace std;

#ifndef NODETYPE
#define NODETYPE

struct NodeType
{
    Station info;
    NodeType *next;
};

#endif
