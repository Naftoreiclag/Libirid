/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef XMLSAVELOADER_H
#define XMLSAVELOADER_H

#include <string>

namespace node
{
    class Node;
}

namespace XmlSaveLoader
{
    node::Node* loadFromFile(std::string fileName);
}

#endif // XMLSAVELOADER_H
