#ifndef XML_PROCESS_H
#define XML_PROCESS_H

#include "tinyxml2.h"

#define  VERSION_ENCODING_STANDALONE   "xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\""
#define     XML_ROOT                    ("Doc")
#define		NORTH_DEV_NODE				("North")
#define		DEV_TYPE					("DevType")
#define		DEV_INDEX					("DevIndex")

#define		NORTH_VS_SOUTH_NODE			("N_VS_S")
#define		NORTH_METE_ID				("N_MeteID")
#define		NORTH_METE_INDEX			("N_MeteIndex")

#define		SOUTH_FACTORY				("S_Factory")
#define		SOUTH_DEV_TYPE				("S_DevType")
#define		SOUTH_DEV_INDEX				("S_DevIndex")
#define		SOUTH_CHANNEL				("S_Chnnl")
#define     SOUHT_CHANNEL_TYPE			("S_ChnnlType")

int createXML(const char* xmlPath);

int CreateNorth_vs_Southxml(const char* xmlPath);

#endif // XXML_PROCESS_H
