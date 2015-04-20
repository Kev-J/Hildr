#include "hildr-tools/XmlConfig.h"

#include <xercesc/util/PlatformUtils.hpp>
#include <iostream>

using namespace HildrTools;

xercesc::XercesDOMParser *XmlConfig::m_parser = 0;

XmlConfig::XmlConfig(sf::String filePath)
:m_xmlDoc(0), m_filePath(filePath)
{
}

XmlConfig::~XmlConfig()
{
}

bool XmlConfig::parse()
{
    try {
        m_parser->parse(m_filePath.toAnsiString().c_str());
    } catch (xercesc::XMLException& e) {
        char* message = xercesc::XMLString::transcode(e.getMessage());
        std::cerr << "Failed to parse XML file " << m_filePath.toAnsiString() << ": " << message << std::endl;
        xercesc::XMLString::release( &message );
        return false;
    }

    m_xmlDoc = m_parser->getDocument();

    if (m_xmlDoc == 0) {
        std::cerr << "Failed to parse XML file " << m_filePath.toAnsiString() << std::endl;
        return false;
    } else {
        return true;
    }
}

void XmlConfig::release()
{
    if (m_xmlDoc) {
        m_xmlDoc->release();
        m_xmlDoc = 0;
    }
}

bool XmlConfig::initializeSubsystem()
{
    try {
        xercesc::XMLPlatformUtils::Initialize();
    } catch (xercesc::XMLException& e) {
        char* message = xercesc::XMLString::transcode( e.getMessage() );
        std::cerr << "Failed to terminate XML: " << message << std::endl;
        xercesc::XMLString::release( &message );
        return false;
    }

    m_parser = new xercesc::XercesDOMParser();

    if (m_parser != 0)
        return true;
    else
        return false;
}

void XmlConfig::terminateSubsystem()
{
    delete m_parser;

    try {
        xercesc::XMLPlatformUtils::Terminate();
    } catch( xercesc::XMLException& e ) {
        char* message = xercesc::XMLString::transcode( e.getMessage() );
        std::cerr << "Failed to terminate XML: " << message << std::endl;
        xercesc::XMLString::release( &message );
    }
}

xercesc::DOMNodeList* XmlConfig::getChildrenNode(const xercesc::DOMNode* parent, const char *childrenTag)
{
    XMLCh* childrenTagTemp = xercesc::XMLString::transcode(childrenTag);
    xercesc::DOMNodeList *childrenList = 0;

    if (parent->getNodeType() == xercesc::DOMNode::DOCUMENT_NODE) {
        const xercesc::DOMDocument *doc = dynamic_cast<const xercesc::DOMDocument*>(parent);
        if (doc != 0)
            childrenList = doc->getElementsByTagName(childrenTagTemp);
    }

    if (parent->getNodeType() == xercesc::DOMNode::ELEMENT_NODE) {
        const xercesc::DOMElement *elem = dynamic_cast<const xercesc::DOMElement*>(parent);
        if (elem != 0)
            childrenList = elem->getElementsByTagName(childrenTagTemp);
    }

    xercesc::XMLString::release(&childrenTagTemp);

    return childrenList;
}

xercesc::DOMNode* XmlConfig::getDocumentElement()
{
    if (m_xmlDoc == 0) {
        return 0;
    }

    return static_cast<xercesc::DOMNode*>(m_xmlDoc);
}
