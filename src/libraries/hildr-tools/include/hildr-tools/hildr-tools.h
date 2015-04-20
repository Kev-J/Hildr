#ifndef HILDR_TOOLS_H
#define HILDR_TOOLS_H

#include "hildr-tools/constants.h"
#include "hildr-tools/XmlConfig.h"

namespace HildrTools {
	/* Must be called once */
	bool initializeSubsystems(void);

	/* Must be called at the end of the program */
	void terminateSubsystems(void);
};

#endif
