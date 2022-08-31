
// STLDataStructureDlg.h: 头文件
//

#pragma once
#include <iostream>
#include <io.h>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>    // std::find   std::sort
#include <functional>
using namespace std;

const int ARRAY_SIZE = 100000;
const int VECTOR_SIZE = 500000;
const int LIST_SIZE = 1000000;

// CSTLDataStructureDlg 对话框
class CSTLDataStructureDlg : public CDialogEx
{
// 构造
public:
	CSTLDataStructureDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STLDATASTRUCTURE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedButtonArray();




public:
	array<long, ARRAY_SIZE> arrayData;		//array
	vector<string> vectorData;
	list<string> listData;
	forward_list<string> forward_listData;
	deque<string> dequeData;
	stack<string> stackData;
	queue<string> queueData;
	multiset<string> multisetData;
	multimap<long, string> multimapData;
	unordered_multiset<string> unordered_multisetData;
	unordered_map<long, string> unordered_multimapData;
	set<string> setData;
	map<long, string> mapData;
	unordered_set <string> unordered_setData;
	unordered_map<long, string> unordered_mapData;
	CListBox m_ShowTipList;
	void ShowTipToList(CString strTip);

	afx_msg void OnBnClickedButtonVector();
	afx_msg void OnBnClickedButtonList();
	afx_msg void OnBnClickedButtonForwordlist();
	afx_msg void OnBnClickedButtonDeque();
	afx_msg void OnBnClickedButtonStack();
	afx_msg void OnBnClickedButtonQueue();
	afx_msg void OnBnClickedButtonMultiset();
	afx_msg void OnBnClickedButtonMultimap();
	afx_msg void OnBnClickedButtonUnorderMultiset();
	afx_msg void OnBnClickedButtonUnorderMultimap();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonSet();
	afx_msg void OnBnClickedButtonMap();
	afx_msg void OnBnClickedButtonUnorderSet();
	afx_msg void OnBnClickedButtonUnorderMap();
	afx_msg void OnBnClickedButtonSequenceC();
	afx_msg void OnBnClickedButtonLambda();
	afx_msg void OnBnClickedButtonThread();
	afx_msg void OnBnClickedButtonInitializerList();
	afx_msg void OnBnClickedButtonSixComponents();
};
