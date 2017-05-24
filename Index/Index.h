/*
** Build index
**
** @ Desc: 
** @ Author: ylyang
** @ Email: yangyulian202@gmail.com
** @ Date: 2016-6-10
*/

#include <stdio>
#include <stdint>
#include <algorithm>
#include <map>
#include "Config.h"
#include "Interface.h"

#define INDEXVERSION "1.0"
#define SESSIONNAME "[Index::Generate Index]"
#define MAXSTRLEN 65536
#define DOCLISTLEN 7

typedef uint32_t t_doclist_item;

typedef struct hashitem_s
{
	uint32_t term; 
	void * itemptr; 
	struct hashitem_s * nextitem;
} hashitem_t;

typedef struct termdoclist_s
{
	t_doclist_item doclist[DOCLISTLEN];
	uint8_t docnum; 
	struct termdoclist_s * next;
} termdoclist_t;

typedef struct termitem_s // inverted index
{
	uint32_t termid; 
	termdoclist_t * termstart; 
	termdoclist_t * termend; 
} termitem_t;  


class Index 
{
    public:
        Index();

        int load_term_map(const char* input, std::map<uint32_t, uint32_t>& term_map);
        void segment(const char* text, vector<uint32_t> &terms, uint32_t term_num);
        void *insertitem(uint32_t term, void * itemptr, hashitem_t * table, uint32_t hashsize,
                uint32_t *hashtop); // insert term to hashtable
        int buildindex(); // build index

    private: 
        FILE * fsrc; // doc file
        FILE * fwordinfo, *finvindex, *finvdoc; // index file
        uint32_t termhashtop = TERMHASHSIZE; // 
        hashitem_t * termhashlist = NULL; // hash list
}
