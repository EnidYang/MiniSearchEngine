#include "Config.h"

#define GETSTRINGVALUE(configureitem, result, size_limit) \
if (config.get_string_value(key, configureitem, value) == 0){\
	strncpy(result, value.c_str(), size_limit);\
} else {\
	printf("[Config] [Error getting configuration item %s]\n", configureitem);\
	return -1;\
}

#define GETINTVALUE(configureitem, result) \
if (config.get_string_value(key, configureitem, value) == 0){\
	result = ACE_OS::atoi(value.c_str());\
} else {\
	printf("[Config] [Error getting configuration item %s]\n", configureitem);\
	return -1;\
}

int IndexConfig::load_config(const char * configname)
{
	ACE_Configuration_Heap config;
	ACE_Registry_ImpExp impexp(config);
	ACE_Configuration_Section_Key key;
	ACE_TString value;

	if (config.open() != 0 || impexp.import_config(configname) != 0) {
		printf("[Config] [Error in reading the configuration]\n");
		return -1;
	}

	GETSTRINGVALUE("doc_file", doc_file, MAXPATHLEN);
	GETSTRINGVALUE("term_info_file", term_info_file, MAXPATHLEN);
	GETSTRINGVALUE("inv_index_file", inv_index_file, MAXPATHLEN);
	GETSTRINGVALUE("inv_doc_file", inv_doc_file, MAXPATHLEN);
	GETSTRINGVALUE("dict_file", dict_file, MAXPATHLEN);

	GETINTVALUE("term_doc_size",term_doc_size);
	GETINTVALUE("term_table_size",term_table_size);

	return 0;
}

