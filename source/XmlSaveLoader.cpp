/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "XmlSaveLoader.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

// Node Stuff
// ==========
#include "node/Node.h"

#include "node/Node_Expanse.h"
#include "node/Node_World.h"
#include "node/Node_Area.h"
#include "node/Node_Portal.h"
#include "node/Node_Entity.h"
#include "node/Node_Script.h"
#include "node/Node_PlayerScript.h"
#include "node/Node_StringValue.h"
#include "node/Node_Folder.h"

// XML Stuff
// =========
#include "RapidXml/rapidxml.hpp"

// Stoux Stuff
// ===========
#include "Stox/stox.hpp"

using namespace rapidxml;

namespace XmlSaveLoader
{
    namespace
    {
        node::Node* createNewNodeFromXml(xml_node<>* xmlNode)
        {
            node::Node* returnVal;

            std::string nodeType = xmlNode->name();

            std::cout << nodeType << std::endl;

            return returnVal;
        }

        void recusiveFunc(node::Node* baseNode, xml_node<>* xmlNode)
        {
            for(xml_node<>* xmlChild = xmlNode->first_node(); xmlChild; xmlChild = xmlChild->next_sibling())
            {
                createNewNodeFromXml(xmlChild);

                recusiveFunc(nullptr, xmlChild);
            }
        }
    }

    node::Node* loadFromFile(std::string saveFileName)
    {
        // Load
        // ====

        // The save XML document
        xml_document<> doc;

        // The generic document and vector buffer
        std::ifstream saveFile(saveFileName);

        // Check if we could not open the file for some reason
        if(!saveFile.is_open())
        {
            throw "Could not open file " + saveFileName;
        }

        // Parse
        // =====

        // Make a buffer to hold this stuff in
        std::stringstream buffer;

        // Pump it full of string
        buffer << saveFile.rdbuf();

        // Close the file, since we won't need it anymore
        saveFile.close();

        // Make a string to hold the buffer contents
        std::string saveFileContent(buffer.str());

        // Pass that into the document parser
        doc.parse<0>(&saveFileContent[0]);

        // Translate into Nodes
        // ====================

        xml_node<>* root_node = doc.first_node("expanse");

        unsigned long long ageStr = stox::stoull(root_node->first_attribute("age"));

        node::Node* expanse = new node::NodeExpanse(ageStr);

        recusiveFunc(nullptr, root_node);
    }
}
