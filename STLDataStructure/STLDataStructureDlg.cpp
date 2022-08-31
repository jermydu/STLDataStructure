
// STLDataStructureDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "STLDataStructure.h"
#include "STLDataStructureDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//string 排序
int compareString(const void* a, const void* b)
{
	if (*(string*)a < *(string*)b) return -1;
	if (*(string*)a == *(string*)b) return 0;
	if (*(string*)a > * (string*)b) return 1;
}

// long  比大小                                
int compareLongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);
}
//CString转string
string toString(CString cs) {
#ifdef _UNICODE
	//如果是unicode工程
	USES_CONVERSION;
	std::string str(W2A(cs));
	return str;
#else
	//如果是多字节工程 
	std::string str(cs.GetBuffer());
	cs.ReleaseBuffer();
	return str;
#endif
}

//string转CString
CString toCString(string str) {
#ifdef _UNICODE
	//如果是unicode工程
	USES_CONVERSION; CString s(str.c_str());
	CString ans(str.c_str());
	return ans;
#else
	//如果是多字节工程
	CString ans;
	ans.Format("%s", str.c_str());
	return ans;
#endif 
}

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSTLDataStructureDlg 对话框



CSTLDataStructureDlg::CSTLDataStructureDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STLDATASTRUCTURE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSTLDataStructureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SHOW_TIP, m_ShowTipList);
}

BEGIN_MESSAGE_MAP(CSTLDataStructureDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ARRAY, &CSTLDataStructureDlg::OnBnClickedButtonArray)
	ON_BN_CLICKED(IDC_BUTTON_VECTOR, &CSTLDataStructureDlg::OnBnClickedButtonVector)
	ON_BN_CLICKED(IDC_BUTTON_LIST, &CSTLDataStructureDlg::OnBnClickedButtonList)
	ON_BN_CLICKED(IDC_BUTTON_FORWORDLIST, &CSTLDataStructureDlg::OnBnClickedButtonForwordlist)
	ON_BN_CLICKED(IDC_BUTTON_DEQUE, &CSTLDataStructureDlg::OnBnClickedButtonDeque)
	ON_BN_CLICKED(IDC_BUTTON_STACK, &CSTLDataStructureDlg::OnBnClickedButtonStack)
	ON_BN_CLICKED(IDC_BUTTON_QUEUE, &CSTLDataStructureDlg::OnBnClickedButtonQueue)
	ON_BN_CLICKED(IDC_BUTTON_MULTISET, &CSTLDataStructureDlg::OnBnClickedButtonMultiset)
	ON_BN_CLICKED(IDC_BUTTON_MULTIMAP, &CSTLDataStructureDlg::OnBnClickedButtonMultimap)
	ON_BN_CLICKED(IDC_BUTTON_UNORDER_MULTISET, &CSTLDataStructureDlg::OnBnClickedButtonUnorderMultiset)
	ON_BN_CLICKED(IDC_BUTTON_UNORDER_MULTIMAP, &CSTLDataStructureDlg::OnBnClickedButtonUnorderMultimap)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CSTLDataStructureDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_SET, &CSTLDataStructureDlg::OnBnClickedButtonSet)
	ON_BN_CLICKED(IDC_BUTTON_MAP, &CSTLDataStructureDlg::OnBnClickedButtonMap)
	ON_BN_CLICKED(IDC_BUTTON_UNORDER_SET, &CSTLDataStructureDlg::OnBnClickedButtonUnorderSet)
	ON_BN_CLICKED(IDC_BUTTON_UNORDER_MAP, &CSTLDataStructureDlg::OnBnClickedButtonUnorderMap)
	ON_BN_CLICKED(IDC_BUTTON_SEQUENCE_C, &CSTLDataStructureDlg::OnBnClickedButtonSequenceC)
	ON_BN_CLICKED(IDC_BUTTON_LAMBDA, &CSTLDataStructureDlg::OnBnClickedButtonLambda)
	ON_BN_CLICKED(IDC_BUTTON_THREAD, &CSTLDataStructureDlg::OnBnClickedButtonThread)
	ON_BN_CLICKED(IDC_BUTTON_INITIALIZER_LIST, &CSTLDataStructureDlg::OnBnClickedButtonInitializerList)
	ON_BN_CLICKED(IDC_BUTTON_SIX_COMPONENTS, &CSTLDataStructureDlg::OnBnClickedButtonSixComponents)
END_MESSAGE_MAP()

// CSTLDataStructureDlg 消息处理程序
CSTLDataStructureDlg* g_pDlg = NULL;
BOOL CSTLDataStructureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	HWND m_hwnd = this->GetSafeHwnd();

	g_pDlg = this;
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSTLDataStructureDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSTLDataStructureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSTLDataStructureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//清空信息
void CSTLDataStructureDlg::OnBnClickedButtonClear()
{
	// TODO: 在此添加控件通知处理程序代码
	while (m_ShowTipList.GetCount() > 0)
	{
		m_ShowTipList.DeleteString(0);
	}
}

//显示信息
void CSTLDataStructureDlg::ShowTipToList(CString strTip)
{
	m_ShowTipList.InsertString(0, strTip);
	while (m_ShowTipList.GetCount() > 200)
	{
		m_ShowTipList.DeleteString(200);
	}
}

//array
void CSTLDataStructureDlg::OnBnClickedButtonArray()
{
	//array 初始化
	array<double, 10> ·;//未显式指定元素的值,各个元素的值是不确定的（array 容器不会做默认初始化操作）
	array<double, 10> array2{};//容器中所有的元素都会被初始化为 0.0。
	array<double, 10> array3{ 0.1,0.2,0.3,0.4 };//初始化了前 4 个元素，剩余的元素都会被初始化为 0.0

	//元素访问
	array<string, 5> words{ "one","two","three","four","five" };
	string strword = "";
	strword = words[3];		//1 不进行边境检查
	strword = words.at(3);	//2 进行边境检查
	strword = get<3>(words);  //3 只能访问模板参数指定的元素，编译器在编译时会对它进行检查
	strword = *(words.data() + 3);	//4 data 获得首个元素指针
	//5 size 获得元素个数
	for (size_t i = 0; i < words.size(); ++i)
	{
		strword = words[i];
	}
	//6 使用范围循环
	for (auto word1:words)
	{
		strword = word1;
	}

	//7 存储字符串
	array<char, 50>a{ 'h','d' };
	int n = sizeof(&a[0]);
	int n1 = strlen("http://c.biancheng.net/stl");
	strcpy_s(&a[0], n1 + 1,"http://c.biancheng.net/stl");
	printf("%s", &a[0]);
	printf("%s", &a[1]);

	ShowTipToList(_T("array++++++++++++++++++++++++"));
	clock_t timestart = clock();
	for (long i = 0; i < ARRAY_SIZE; ++i)
	{
		arrayData[i] = rand();
	}
	CString strTip = _T("");
	strTip.Format(_T("向array添加%d个元素耗时%d毫秒"), ARRAY_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("array的大小：%d"), arrayData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("array的第一个元素：%d"), arrayData.front());
	ShowTipToList(strTip);
	strTip.Format(_T("array的最后一个元素：%d"), arrayData.back());
	ShowTipToList(strTip);
	strTip.Format(_T("array的地址：0x%x"), arrayData.data());
	ShowTipToList(strTip);

	timestart = clock();
	//排序 
	qsort(arrayData.data(), ARRAY_SIZE, sizeof(long), compareLongs);
	//sort(arrayData.begin(), arrayData.end());
	strTip.Format(_T("array排序耗时%d毫秒"),clock() - timestart);
	ShowTipToList(strTip);

	timestart = clock();
	//二分查找  
	long ltag = 2000;
	long* pItem = (long*)bsearch(&ltag, arrayData.data(), ARRAY_SIZE, sizeof(long), compareLongs);
	if (pItem)
	{
		strTip.Format(_T("array中查找某一个元素耗时%d毫秒"), clock() - timestart);
	}
	else
	{
		strTip = _T("没有查到");
	}
	ShowTipToList(strTip);
	ShowTipToList(_T("array++++++++++++++++++++++++"));
}

//vector  增加空间方式 在新的空间找一个*2的空间 把之前的数据copy过去 1->2->4->8->16
void CSTLDataStructureDlg::OnBnClickedButtonVector()
{
	// TODO: 在此添加控件通知处理程序代码
	//初始化
	//1、初始化空的vector
	std::vector<double> v1;
	v1.reserve(20);//增加容器容量 调用 reserve() 不会影响已存储的元素，也不会生成任何元素
	//2、指定初始值和元素个数
	std::vector<int> v2{ 2, 3, 5, 7, 11, 13, 17, 19 };
	std::vector<int> v3(20);//指定元素个数初始值为0
	std::vector<int> v4(20,2);//指定元素个数初始值为2
	//4、通过存储元素类型相同的其它 vector 容器，也可以创建新的 vector 容器
	std::vector<char>v5(5, 'c');
	std::vector<char>v6(v5);
	//5、用一对指针或者迭代器来指定初始值的范围
	int array[] = { 1,2,3 };
	std::vector<int>v7(array, array + 2);//values 将保存{1,2}
	std::vector<int>v8{ 1,2,3,4,5 };
	std::vector<int>v9(std::begin(v8), std::begin(v8) + 3);//value2保存{1,2,3}

	//访问元素（单个元素）
	vector<int> values{1,2,3,4,5,6,7,8,9};
	int n = values[0];		//1、指定下标 不进行边境检查
	n = values.at(1);		//2、at() 成员函数，当传给 at() 的索引会造成越界时，会抛出std::out_of_range异常
	n = values.front(); n = values.back();		//3、首元素  尾元素
	n = *(values.data() + 2); //4、values.data()返回首元素地址指针
	//访问元素（多个元素）
	for (int i = 0; i < values.size(); i++) //5、values.size() 返回元素个数
	{
		
	}
	for (auto value : values)	//6、使用范围循环
	{
		n = value;
	}
	for (auto first = values.begin(); first < values.end(); ++first)//7、通过begin/end遍历容器
	{
		n = *first;
	}

	////插入元素
	//push_back() 向容器尾部添加元素时，首先创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素）；
	//emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程。
	vector<int> value1{};
	value1.push_back(1);
	value1.push_back(2);
	value1.emplace_back(3);
	value1.emplace_back(4);

	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("vector++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < VECTOR_SIZE; ++i)
	{
		CString strindex = _T("");
		strindex.Format(_T("%d"), i);
		//ShowTipToList(strindex);
		try
		{
			snprintf(buf, 10, "%d", rand());
			vectorData.push_back((string)buf);
		}
		catch (CMemoryException* e)
		{
			
			strTip.Format(_T("vector 最大%d"),i);
			ShowTipToList(strTip);
			abort();
		}
		
	}

	strTip.Format(_T("向vector添加%d个元素耗时%d毫秒"), VECTOR_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("vector的元素大小：%d"), vectorData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("vector的第一个元素：%s"), toCString(vectorData.front()));
	ShowTipToList(strTip);
	strTip.Format(_T("vector的最后一个元素：%s"), toCString(vectorData.back()));
	ShowTipToList(strTip);
	strTip.Format(_T("vector的地址：0x%x"), vectorData.data());
	ShowTipToList(strTip);
	strTip.Format(_T("vector的实际内存大小：%d"), vectorData.capacity());
	ShowTipToList(strTip);

	//普通查找
	timestart = clock();
	string sFind = "12679";
	auto pItem = find(vectorData.begin(),vectorData.end(), sFind);
	if (pItem != vectorData.end())
	{
		strTip.Format(_T("通过find找到%s 查询时间%d毫秒"), toCString(*pItem),clock()-timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过find没有找到"));
	}
	//二分查找
	timestart = clock();
	sort(vectorData.begin(),vectorData.end());
	string *pItemString = (string *)bsearch(&sFind, vectorData.data(), vectorData.size(), sizeof(string), compareString);
	if (pItemString != NULL)
	{
		strTip.Format(_T("通过bsearch找到%s 查询时间%d毫秒"), toCString(*pItemString), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过bsearch没有找到"));
	}
	ShowTipToList(_T("vector++++++++++++++++++++++++"));
}

//list
void CSTLDataStructureDlg::OnBnClickedButtonList()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("list++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			listData.push_back((string)buf);
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("list 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向list添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("list的元素大小：%d"), listData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("list可以存放的元素大小：%d"), listData.max_size());
	ShowTipToList(strTip);
	strTip.Format(_T("list的第一个元素：%s"), toCString(listData.front()));
	ShowTipToList(strTip);
	strTip.Format(_T("list的最后一个元素：%s"), toCString(listData.back()));
	ShowTipToList(strTip);

	//查询
	timestart = clock();
	string sFind = "12679";
	auto pItem = find(listData.begin(), listData.end(), sFind);
	if (pItem != listData.end())
	{
		strTip.Format(_T("通过find找到%s 查询时间%d毫秒"), toCString(*pItem), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过find没有找到"));
	}

	//排序
	timestart = clock();
	listData.sort();   //list内部的sort方法
	strTip.Format(_T("通过listsort排序耗时%d毫秒"), clock() - timestart);
	ShowTipToList(strTip);

	ShowTipToList(_T("list++++++++++++++++++++++++"));
}

//ForwordList  
void CSTLDataStructureDlg::OnBnClickedButtonForwordlist()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("forwardlist++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			forward_listData.push_front((string)buf);
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("forward_listData 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向forward_listData添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("forward_listData可以存放的元素大小：%d"), forward_listData.max_size());
	ShowTipToList(strTip);
	strTip.Format(_T("forward_listData的第一个元素：%s"), toCString(forward_listData.front()));
	ShowTipToList(strTip);
	//查询
	timestart = clock();
	string sFind = "12679";
	auto pItem = find(forward_listData.begin(), forward_listData.end(), sFind);
	if (pItem != forward_listData.end())
	{
		strTip.Format(_T("通过find找到%s 查询时间%d毫秒"), toCString(*pItem), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过find没有找到"));
	}

	//排序
	timestart = clock();
	forward_listData.sort();   //list内部的sort方法
	strTip.Format(_T("通过forwardlistsort排序耗时%d毫秒"), clock() - timestart);
	ShowTipToList(strTip);

	ShowTipToList(_T("forwardlist++++++++++++++++++++++++"));
}

//deque 双向进出
void CSTLDataStructureDlg::OnBnClickedButtonDeque()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("deque++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			dequeData.push_back((string)buf);
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("list 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向deque添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("deque的元素大小：%d"), dequeData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("deque可以存放的元素大小：%d"), dequeData.max_size());
	ShowTipToList(strTip);
	strTip.Format(_T("deque的第一个元素：%s"), toCString(dequeData.front()));
	ShowTipToList(strTip);
	strTip.Format(_T("deque的最后一个元素：%s"), toCString(dequeData.back()));
	ShowTipToList(strTip);

	//查询
	timestart = clock();
	string sFind = "12679";
	auto pItem = find(dequeData.begin(), dequeData.end(), sFind);
	if (pItem != dequeData.end())
	{
		strTip.Format(_T("通过find找到%s 查询时间%d毫秒"), toCString(*pItem), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过find没有找到"));
	}

	//排序
	timestart = clock();
	sort(dequeData.begin(), dequeData.end());   //list内部的sort方法
	strTip.Format(_T("通过sort排序耗时%d毫秒"), clock() - timestart);
	ShowTipToList(strTip);

	ShowTipToList(_T("deque++++++++++++++++++++++++"));
}

//stack 先进后出
void CSTLDataStructureDlg::OnBnClickedButtonStack()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("stack++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			stackData.push((string)buf);
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("stack 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向stack添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("stack的元素大小：%d"), stackData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("stack的第一个元素：%s"), toCString(stackData.top()));
	ShowTipToList(strTip);
	stackData.pop();
	strTip.Format(_T("stack的元素大小：%d"), stackData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("stack的第一个元素：%s"), toCString(stackData.top()));
	ShowTipToList(strTip);

	ShowTipToList(_T("stack++++++++++++++++++++++++"));
}

//queue 先进先出
void CSTLDataStructureDlg::OnBnClickedButtonQueue()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("queue++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			queueData.push((string)buf);
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("queue 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向queue添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("queue的元素大小：%d"), queueData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("queue的第一个元素：%s"), toCString(queueData.front()));
	ShowTipToList(strTip);
	strTip.Format(_T("queue的最后一个元素：%s"), toCString(queueData.back()));
	ShowTipToList(strTip);
	queueData.pop();
	strTip.Format(_T("queue的元素大小：%d"), queueData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("queue的第一个元素：%s"), toCString(queueData.front()));
	ShowTipToList(strTip);
	strTip.Format(_T("queue的最后一个元素：%s"), toCString(queueData.back()));
	ShowTipToList(strTip);

	ShowTipToList(_T("queue++++++++++++++++++++++++"));
}

//multiset（可以存放重复数值）   key value 相同  底层红黑树
void CSTLDataStructureDlg::OnBnClickedButtonMultiset()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("multiset++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			multisetData.insert((string)buf);
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("multiset 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向multiset添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("multiset的元素大小：%d"), multisetData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("multiset可以存放的元素大小：%d"), multisetData.max_size());
	ShowTipToList(strTip);

	//查询
	timestart = clock();
	string sFind = "12679";
	auto pItem1 = ::find(multisetData.begin(), multisetData.end(), sFind);
	if (pItem1 != multisetData.end())
	{
		strTip.Format(_T("通过find找到%s 查询时间%d毫秒"), toCString(*pItem1), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过find没有找到"));
	}

	
	timestart = clock();
	auto pItem2 = multisetData.find(sFind);
	
	if (pItem2 != multisetData.end())
	{
		strTip.Format(_T("通过multiset.find找到%s 查询时间%d毫秒"), toCString(*pItem2), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过multiset.find没有找到"));
	}
	

	ShowTipToList(_T("multiset++++++++++++++++++++++++"));
}

//multimap  key-value键值对   底层红黑树  可以重复
void CSTLDataStructureDlg::OnBnClickedButtonMultimap()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("multimap++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());

			//不可以使用[] 进行添加元素
			multimapData.insert(pair<long, string>(i, buf)); 
			//将两个值视为一个单元。容器类别map和multimap就是使用pairs来管理其健值/实值(key/value)的成对元素。
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("multimap 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向multimap添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("multimap的元素大小：%d"), multimapData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("multimap可以存放的元素大小：%d"), multimapData.max_size());
	ShowTipToList(strTip);

	//查询
	timestart = clock();
	long sFind = 12679;
	auto pItem2 = multimapData.find(sFind);  //find 参数为key

	if (pItem2 != multimapData.end())
	{
		strTip.Format(_T("通过multimap.find找到key:%d value:%s 查询时间%d毫秒"), (*pItem2).first, toCString((*pItem2).second), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过multimap.find没有找到"));
	}
	

	ShowTipToList(_T("multimap++++++++++++++++++++++++"));
}

//unordered_multiset  底层哈希表
//篮子要大于等于元素个数，篮子个数大概是元素的2倍
void CSTLDataStructureDlg::OnBnClickedButtonUnorderMultiset()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("unordered_multiset++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			unordered_multisetData.insert((string) buf);
			
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("unordered_multiset 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向unordered_multiset添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multiset的元素大小：%d"), unordered_multisetData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multiset可以存放的元素大小：%d"), unordered_multisetData.max_size());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multiset篮子个数：%d"), unordered_multisetData.bucket_count());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multiset载入因子：%f"), unordered_multisetData.load_factor());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multiset最大篮子个数：%d"), unordered_multisetData.max_bucket_count());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multiset最大载入因子：%f"), unordered_multisetData.max_load_factor());
	ShowTipToList(strTip);

	for (int i = 0;i<100;++i)
	{
		strTip.Format(_T("第[%d]个篮子有[%d]个元素"), i, unordered_multisetData.bucket_size(i));
		ShowTipToList(strTip);
	}

	//查询
	timestart = clock();
	string sFind = "12679";
	auto pItem1 = ::find(unordered_multisetData.begin(), unordered_multisetData.end(), sFind);
	if (pItem1 != unordered_multisetData.end())
	{
		strTip.Format(_T("通过find找到%s 查询时间%d毫秒"), toCString(*pItem1), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过find没有找到"));
	}


	timestart = clock();
	auto pItem2 = unordered_multisetData.find(sFind);

	if (pItem2 != unordered_multisetData.end())
	{
		strTip.Format(_T("通过unordered_multiset.find找到%s 查询时间%d毫秒"), toCString(*pItem2), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过unordered_multiset.find没有找到"));
	}
	
	ShowTipToList(_T("unordered_multiset++++++++++++++++++++++++"));

}

//unordered_multimap  底层哈希表
void CSTLDataStructureDlg::OnBnClickedButtonUnorderMultimap()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("unordered_multimap++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			unordered_multimapData.insert(pair<long,string>(i, (string)buf));

		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("unordered_multimap 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向unordered_multimap添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multimap的元素大小：%d"), unordered_multimapData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multimap可以存放的元素大小：%d"), unordered_multimapData.max_size());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multimap篮子个数：%d"), unordered_multimapData.bucket_count());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multimap载入因子：%f"), unordered_multimapData.load_factor());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multimap最大篮子个数：%d"), unordered_multimapData.max_bucket_count());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_multimap最大载入因子：%f"), unordered_multimapData.max_load_factor());
	ShowTipToList(strTip);


	//查询
	timestart = clock();
	auto pItem2 = unordered_multimapData.find(12);

	if (pItem2 != unordered_multimapData.end())
	{
		strTip.Format(_T("通过unordered_multimap.find找到key:%d value:%s 查询时间%d毫秒"), (*pItem2).first,toCString((*pItem2).second), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过unordered_multimap.find没有找到"));
	}

	ShowTipToList(_T("unordered_multimap++++++++++++++++++++++++"));
}


//set 值不可重复
void CSTLDataStructureDlg::OnBnClickedButtonSet()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("set++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			setData.insert((string)buf);
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("set 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向set添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("set的元素大小：%d"), setData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("set可以存放的元素大小：%d"), setData.max_size());
	ShowTipToList(strTip);

	//查询
	timestart = clock();
	string sFind = "12679";
	auto pItem1 = ::find(setData.begin(), setData.end(), sFind);
	if (pItem1 != setData.end())
	{
		strTip.Format(_T("通过find找到%s 查询时间%d毫秒"), toCString(*pItem1), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过find没有找到"));
	}


	timestart = clock();
	auto pItem2 = setData.find(sFind);

	if (pItem2 != setData.end())
	{
		strTip.Format(_T("通过set.find找到%s 查询时间%d毫秒"), toCString(*pItem2), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过set.find没有找到"));
	}


	ShowTipToList(_T("set++++++++++++++++++++++++"));
}

//map key不可重复
void CSTLDataStructureDlg::OnBnClickedButtonMap()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("multiset++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			mapData[i] = (string)buf;
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("map 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向map添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("map的元素大小：%d"), mapData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("map可以存放的元素大小：%d"), mapData.max_size());
	ShowTipToList(strTip);

	//查询
	timestart = clock();
	auto pItem2 = mapData.find(222);

	if (pItem2 != mapData.end())
	{
		strTip.Format(_T("通过map.find找到key:%d value:%s 查询时间%d毫秒"), (*pItem2).first ,toCString((*pItem2).second), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过map.find没有找到"));
	}


	ShowTipToList(_T("map++++++++++++++++++++++++"));
}

//unorderset 哈希表形式的set
void CSTLDataStructureDlg::OnBnClickedButtonUnorderSet()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("unordered_set++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			unordered_setData.insert((string)buf);
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("unordered_set 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向unordered_set添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_set的元素大小：%d"), unordered_setData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_set可以存放的元素大小：%d"), unordered_setData.max_size());
	ShowTipToList(strTip);

	//查询
	timestart = clock();
	string sFind = "12679";
	auto pItem1 = ::find(unordered_setData.begin(), unordered_setData.end(), sFind);
	if (pItem1 != unordered_setData.end())
	{
		strTip.Format(_T("通过find找到%s 查询时间%d毫秒"), toCString(*pItem1), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过find没有找到"));
	}


	timestart = clock();
	auto pItem2 = unordered_setData.find(sFind);

	if (pItem2 != unordered_setData.end())
	{
		strTip.Format(_T("通过unordered_set.find找到%s 查询时间%d毫秒"), toCString(*pItem2), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过unordered_set.find没有找到"));
	}


	ShowTipToList(_T("unordered_set++++++++++++++++++++++++"));
}

//unordermap 哈希表形式的map
void CSTLDataStructureDlg::OnBnClickedButtonUnorderMap()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strTip = _T("");
	clock_t timestart = clock();
	ShowTipToList(_T("multiset++++++++++++++++++++++++"));
	char buf[10];
	for (long i = 0; i < LIST_SIZE; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			unordered_mapData[i] = (string)buf;
		}
		catch (CMemoryException * e)
		{

			strTip.Format(_T("unordered_map 最大%d"), i);
			ShowTipToList(strTip);
			abort();
		}

	}

	strTip.Format(_T("向unordered_map添加%d个元素耗时%d毫秒"), LIST_SIZE, clock() - timestart);
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_map的元素大小：%d"), unordered_mapData.size());
	ShowTipToList(strTip);
	strTip.Format(_T("unordered_map可以存放的元素大小：%d"), unordered_mapData.max_size());
	ShowTipToList(strTip);

	//查询
	timestart = clock();
	auto pItem2 = unordered_mapData.find(222);

	if (pItem2 != unordered_mapData.end())
	{
		strTip.Format(_T("通过unordered_map.find找到key:%d value:%s 查询时间%d毫秒"), (*pItem2).first, toCString((*pItem2).second), clock() - timestart);
		ShowTipToList(strTip);
	}
	else
	{
		ShowTipToList(_T("通过unordered_map.find没有找到"));
	}


	ShowTipToList(_T("unordered_map++++++++++++++++++++++++"));
}


#pragma region 顺序表

#define SquenceTableSize 10

//顺序表结构
typedef struct SquenceTable_C
{
	int* head;				//动态数组
	int length;				//顺序表的长度
	int size;				//顺序表的存储容量
}squenceTable_C;

//初始化顺序表
squenceTable_C InitSquenceTable()
{
	squenceTable_C tableTest;
	tableTest.head = (int*)malloc(10  * sizeof(int));
	if (!tableTest.head)
	{
		g_pDlg->ShowTipToList(_T("初始化失败！"));
	}
	tableTest.size = SquenceTableSize;
	tableTest.length = 0;

	return tableTest;
}

//遍历顺序表
void DisplaySquenceTable(squenceTable_C table)
{
	for (int i = 0;i< table.size;i++)
	{
		CString strTmp;
		strTmp.Format(_T("%d\n"), table.head[i]);
		g_pDlg->ShowTipToList(strTmp);

	}
}

//C 语言实现顺序表
void CSTLDataStructureDlg::OnBnClickedButtonSequenceC()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowTipToList(_T("顺序表++++++++++++++++++++++++"));
	squenceTable_C tableTest = InitSquenceTable();

	//向顺序表中添加元素
	for (int i = 0; i < SquenceTableSize; i++) {
		tableTest.head[i] = i;
		tableTest.length++;
	}

	DisplaySquenceTable(tableTest);
	
	free(tableTest.head);

	ShowTipToList(_T("顺序表++++++++++++++++++++++++"));
}

#pragma endregion

//多线程
void CSTLDataStructureDlg::OnBnClickedButtonThread()
{
	// TODO: 在此添加控件通知处理程序代码

}

//lambda
void CSTLDataStructureDlg::OnBnClickedButtonLambda()
{
	// TODO: 在此添加控件通知处理程序代码
	int num[4] = { 4, 2, 3, 1 };
	//对 a 数组中的元素进行排序
	sort(num, num + 4, [=](int x, int y) -> bool { return x < y; });
	for (int n : num)
	{
		std::cout << n << " ";
	}


}

//统一的类成员初始化语法
void CSTLDataStructureDlg::OnBnClickedButtonInitializerList()
{
	
}

//六大部件
void CSTLDataStructureDlg::OnBnClickedButtonSixComponents()
{
	int arr[] = {10,20,30,40,50,60,70,80,90};
	std::vector<int, allocator<int>> v(arr,arr+9);
	int count = std::count_if(v.begin(), v.end(), not1(bind2nd(less<int>(), 50)));
	CString strTip;
	strTip.Format(TEXT("容器中大于等于50的数字有%d个"), count);
	ShowTipToList(strTip);
}
