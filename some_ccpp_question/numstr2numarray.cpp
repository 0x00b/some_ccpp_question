/*********************************************************************
** "<0XAB,0X1F,0XFF,<0X11,0X22,0X33>...>" TO int arr {0XAB,0X1F,0XFF,{0X11,0X22,0X33}...}
** notion:  exception
*********************************************************************/

#include "main.h"

#if _NUMSTR_TO_NUMARRAY_

#define TAG_STR		"<"
#define TAG_END		">"
#define TAG_DLT		","
#define TAG_HEX_1	"0X"
#define TAG_HEX_2	"0x"
#define TAG_HEX_L	2
#define HEX			16

#define TYPE_ARR	0
#define TYPE_NUM	1


struct _Node_t_ 
{
	int		type;
	int		nValue;
	_Node_t_* aValue;
	_Node_t_* next;

	_Node_t_()
	{
		next = aValue = NULL;
	}

	~_Node_t_()
	{
		if (aValue != NULL)
		{
			delete aValue;
		}
		if (next != NULL)
		{
			delete next;
		}
	}

};

class  _NumArray_t_
{
public:
	_NumArray_t_()
	{
		m_pArr = new _Node_t_();
	}
	~_NumArray_t_()
	{
		//do some cycle back work
		//clear(m_pArr);
		delete m_pArr;
	}
	void parse(char* str)
	{
		parseOne(m_pArr,&str);
	}
	void parseOne(_Node_t_* pHead ,char** str, char* endTag = TAG_END)
	{
		char* lineEnd = *str;
		_Node_t_* pTmp = NULL;
		_Node_t_* pArr = pHead;
		if (NULL == *str)
		{
			return;
		}
		if (0 != strncmp(*str, TAG_STR, strlen(TAG_STR)) 
			&& 0 != strncmp(*str + strlen(*str) - strlen(endTag), endTag, strlen(endTag)))
		{
			return;
		}
		*str += strlen(TAG_STR);

		while ( NULL!= *str&& NULL != lineEnd &&  0 != strncmp(*str, endTag, strlen(endTag)) )
		{
			lineEnd = strstr(*str, TAG_DLT);
			if (NULL == lineEnd)
			{
				lineEnd = strstr(*str, endTag);
			}
			if (NULL != lineEnd)
			{
				pTmp = new _Node_t_();
				if (0 != strncmp(*str, TAG_STR, strlen(TAG_STR)))
				{
					pTmp->type = TYPE_NUM;
					pTmp->nValue = str2int(*str);

					*str = lineEnd + strlen(TAG_DLT);
				}
				else
				{  
					pTmp->type = TYPE_ARR;
					pTmp->aValue = new _Node_t_();
					parseOne(pTmp->aValue , str, endTag);
				}

				pArr->next = pTmp;
				pArr = pTmp;

				if (0 == strncmp(lineEnd - strlen(endTag), endTag, strlen(endTag)))
				{
					return;
				}
			}
		}
	}

	int str2int(char* str,char* end = TAG_DLT)
	{
		char* t_str = str;
		int ntemp = 0;
		/* 目前只有十六进制，十进制 */
		if (0 == strncmp(t_str, TAG_HEX_1, TAG_HEX_L)
			|| 0 == strncmp(t_str, TAG_HEX_2, TAG_HEX_L))
		{
			/* 0x开头 十六进制 */
			t_str += TAG_HEX_L;
			while (t_str && *t_str && 0 != strncmp(t_str, end, strlen(end)))
			{
				if (isHexChar(*t_str))
				{
					ntemp = ntemp*HEX + char2hex(*t_str);
					t_str++;
				}
				else
				{
					break;
				}
			}
			return ntemp;
		}
		else
		{
			return atoi(t_str);
		}
	}

	inline bool isHexChar(char ch)
	{
		return ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F') || (ch >= '0' && ch <= '9'));
	}

	int char2hex(char ch)
	{
		if (ch >= 'A' && ch <= 'F')
		{
			return ch - 'A' + 10;
		}
		else if (ch >= 'a' && ch <= 'f')
		{
			return ch - 'a' + 10;
		}
		else if (ch >= '0' && ch <= '9')
		{
			return ch - '0';
		}
		return 0;
	}
	void dsp()
	{
		disp(m_pArr);
	}
	void disp(_Node_t_* node)
	{
		_Node_t_* pN = node->next;
		_Node_t_* pCN = NULL;

		printf("{");
		while (pN)
		{
			if ( TYPE_NUM == pN->type)
			{
				printf("%d,", pN->nValue);
			}
			else
			{
				pCN = pN->aValue;
				disp(pCN);
			}
			pN = pN->next;
		}
		printf("},");
	}

private:
	_Node_t_* m_pArr;

};

int main()
{
	char* str = "<123,<0X11,0x22,<0X33,0x444,<0x55,0x66>,0X77>,0x88>,<0X99,0XaA>,<0xBbbB,<0XC,0XDD>,0xEE,0XFF>>";

	//char* str = "<0XAB,0X1F,0XFf4F,0X1331,0X22,0X3333>";

	_NumArray_t_* pNa = new _NumArray_t_();

	pNa->parse(str);

	pNa->dsp();

	delete pNa;

#if defined(_WIN)
	return system("pause");
#else
	return 0;
#endif
}

#endif //_BINARY_SEARCH_