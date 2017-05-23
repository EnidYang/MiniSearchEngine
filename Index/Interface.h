#ifndef _Interface_H_
#define _Interface_H_

#include <stdint>
#include <map>
#include <string>

typedef struct {
	uint32_t id;
	uint32_t weight;
} t_termitem;

// the doc file is supposed to have three fields, title, description and url 
#define MAX_TITLE_LEN 100
#define MAX_DESC_LEN 500
#define MAX_URL_LEN 500

// for queries
#define MAX_QUERY_CHAR_NUM 20
#define MAX_QUERYTERM_NUM 20
#define MAX_INDEXTERM_NUM 40
#define MAX_MESSAGE_NUM 1000

// for docs
#define MAX_TITLE_TERM_NUM 60
#define MAX_DESC_TERM_NUM 120

typedef struct {
	char		query_word[MAX_QUERY_CHAR_NUM];
	uint16_t	term_num; 
	uint32_t	term_id[MAX_QUERYTERM_NUM];
	uint32_t    term_type[MAX_QUERYTERM_NUM];
	uint32_t    term_cat[MAX_QUERYTERM_NUM];
	uint32_t 	term_weight[MAX_QUERYTERM_NUM];
	uint16_t	synonym_num;
	uint32_t	synonym_id[MAX_QUERYTERM_NUM];

    uint32_t    index_term_num;
    uint32_t    index_term_id[MAX_INDEXTERM_NUM];
} t_query;

// for retrieval result
struct t_res{
	uint32_t docid;
	uint32_t weight;
    char message[MAX_MESSAGE_NUM];
	bool isSelect;

	t_res():docid(0),weight(0),isSelect(0)
	{
	}

	t_res(const t_res& a):docid(a.docid), weight(a.weight), isSelect(a.isSelect)
	{
		strcpy(message, a.message);
	}

	t_res& operator=(const t_res& a)
	{
		docid = a.docid;
		weight = a.weight;
		isSelect = a.isSelect;
		strcpy(message, a.message);
		return *this;
	}
};

typedef struct {
	uint32_t        termid;                 // term id
	uint32_t        doc_list;               // 该term在doclist文件中的doc索引
	uint32_t        doc_num;                // doc的个数
}t_inv_index;

typedef struct {
	uint32_t    docid;                           // doc id
	char        title[MAX_TITLE_LEN];             // title
	char        desc[MAX_DESC_LEN];               // abstract description
	char        url[MAX_URL_LEN];
	uint8_t     title_term_num;
	uint32_t    desc_term_num;

	uint8_t     title_term_num;                        // total term number
	uint32_t    title_term_id[MAX_TITLE_TERM_NUM];     
    uint32_t    title_term_type[MAX_TITLE_TERM_NUM];
    uint32_t    title_term_cate[MAX_TITLE_TERM_NUM];
	uint32_t    title_term_weight[MAX_TITLE_TERM_NUM]; 
	uint8_t     desc_term_num;                        
	uint32_t    desc_term_id[MAX_DESC_TERM_NUM];      
    uint32_t    desc_term_type[MAX_DESC_TERM_NUM];
    uint32_t    desc_term_cate[MAX_DESC_TERM_NUM];
    uint32_t    desc_term_weight[MAX_DESC_TERM_NUM];
} t_doc_info;

typedef struct {
	t_res res;
	t_doc_info * docinfo;
} t_rerank;

#endif


