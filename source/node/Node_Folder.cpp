/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_Folder.h"

using namespace node;

Node_Folder::Node_Folder(std::string name, Node* parent)
: Node(name, NT_FOLDER, parent)
{
    //ctor
}

Node_Folder::~Node_Folder()
{
    //dtor
}
