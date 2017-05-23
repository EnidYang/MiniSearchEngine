/**
 *	Read configuration file
 *
 *	@author : ylyang
 *	@email : yangyulian202@gmail.com
 *	@date : 2016-6-8
 *
 */

#ifndef _INDEX_CONFIG_H_
#define _INDEX_CONFIG_H_

#include <ace/Configuration.h>
#include <ace/Configuration_Import_Export.h>

class IndexConfig
{
	public:

		/// 获取单例的指针
		IndexConfig();

		int load_config(const char * configname);

		uint32_t term_doc_size;
		uint32_t term_table_size;
		
        char doc_file[MAXPATHLEN];
        char term_info_file[MAXPATHLEN];
		char inv_index_file[MAXPATHLEN];
		char inv_doc_file[MAXPATHLEN];

        /// other possible configuration
        char dict_file[MAXPATHLEN]; // for text segmentation
};

#endif

