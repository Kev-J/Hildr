#ifndef XML_CONFIG_H
#define XML_CONFIG_H

#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>
#include <SFML/System.hpp>

namespace HildrTools {
    class XmlConfig {

        public:
            XmlConfig(sf::String filePath);
            ~XmlConfig();

            /* Must be called once */
            static bool initializeSubsystem(void);

            /* Must be called at the end of the program */
            static void terminateSubsystem(void);

            bool parse(void);
            void release(void);

            xercesc::DOMNodeList* getChildrenNode(const xercesc::DOMNode* parent, const char *childrenTag);
            xercesc::DOMNode* getDocumentElement();

        private:
            static xercesc::XercesDOMParser* m_parser;

            xercesc::DOMDocument* m_xmlDoc;

            sf::String m_filePath;
    };
};

#endif
