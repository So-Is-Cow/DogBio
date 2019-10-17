
// dogdog191002Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "dogdog191002.h"
#include "dogdog191002Dlg.h"
#include "afxdialogex.h"
#include "TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// Cdogdog191002Dlg ��ȭ ����

//Dogdata _dog_info;


Cdogdog191002Dlg::Cdogdog191002Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DOGDOG191002_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void Cdogdog191002Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, _edit_name);
	DDX_Control(pDX, IDC_EDIT_AGE, _edit_age);
	DDX_Control(pDX, IDC_EDIT_SPECIES, _edit_species);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, _edit_address);
	DDX_Control(pDX, IDC_BUTTON_LOAD_IMG, _btn_load_image);
	DDX_Control(pDX, IDC_BUTTON_OPEN_CAMERA, _btn_open_camera);
	DDX_Control(pDX, IDC_BUTTON1, _btn_left);
	DDX_Control(pDX, IDC_BUTTON2, _btn_right);
}

BEGIN_MESSAGE_MAP(Cdogdog191002Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cdogdog191002Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cdogdog191002Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_IMG, &Cdogdog191002Dlg::OnBnClickedButtonLoadImg)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_CAMERA, &Cdogdog191002Dlg::OnBnClickedButtonOpenCamera)

END_MESSAGE_MAP()


// Cdogdog191002Dlg �޽��� ó����

BOOL Cdogdog191002Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	_dog_info.name = "solsol";
	_dog_info.age = "25";
	_dog_info.address = "����� ���빮�� ����";
	_dog_info.species = "�ΰ�";
	e_flag = 0;
	EditOffMode();


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Cdogdog191002Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Cdogdog191002Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Cdogdog191002Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cdogdog191002Dlg::EditOnMode()
{
	//_edit_name.SetReadOnly(false);
	//_edit_age.SetReadOnly(false);
	//_edit_species.SetReadOnly(false);
	//_edit_address.SetReadOnly(false);
	_edit_name.EnableWindow(1);
	_edit_age.EnableWindow(1);
	_edit_address.EnableWindow(1);
	_edit_species.EnableWindow(1);
	_edit_name.ModifyStyleEx(0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME | SWP_FRAMECHANGED);
	_edit_age.ModifyStyleEx(0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME | SWP_FRAMECHANGED);
	_edit_species.ModifyStyleEx(0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME | SWP_FRAMECHANGED);
	_edit_address.ModifyStyleEx(0, WS_EX_CLIENTEDGE, SWP_DRAWFRAME | SWP_FRAMECHANGED);
	_btn_load_image.ShowWindow(1);
	_btn_open_camera.ShowWindow(1);
	_edit_name.ShowWindow(1);
	_edit_age.ShowWindow(1);
	_edit_address.ShowWindow(1);
	_edit_species.ShowWindow(1);
	//GetDlgItemText(IDC_BUTTON1, "Save");
	_btn_left.SetWindowTextA((LPCTSTR)"Save");
	_btn_right.SetWindowTextA((LPCTSTR)"Cancel");
	
}
void Cdogdog191002Dlg::EditOffMode()
{
	//_edit_name.SetReadOnly(true);
	//_edit_age.SetReadOnly(true);
	//_edit_species.SetReadOnly(true);
	//_edit_address.SetReadOnly(true);
	_edit_name.SetWindowTextA((LPCTSTR)_dog_info.name);
	_edit_age.SetWindowTextA((LPCTSTR)_dog_info.age);
	_edit_address.SetWindowTextA((LPCTSTR)_dog_info.address);
	_edit_species.SetWindowTextA((LPCTSTR)_dog_info.species);
	_edit_name.EnableWindow(0);
	_edit_age.EnableWindow(0);
	_edit_address.EnableWindow(0);
	_edit_species.EnableWindow(0);
	_edit_name.ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_DRAWFRAME | SWP_FRAMECHANGED);
	_edit_age.ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_DRAWFRAME | SWP_FRAMECHANGED);
	_edit_species.ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_DRAWFRAME | SWP_FRAMECHANGED);
	_edit_address.ModifyStyleEx(WS_EX_CLIENTEDGE, 0, SWP_DRAWFRAME | SWP_FRAMECHANGED);
	_btn_load_image.ShowWindow(0);
	_btn_open_camera.ShowWindow(0);
	/*_btn_left.GetWindowTextW("Edit");
	_btn_left.GetWindowTextW("Delete");*/
	_btn_left.SetWindowTextA((LPCTSTR)"Edit");
	_btn_right.SetWindowTextA((LPCTSTR)"Delete");

}

void Cdogdog191002Dlg::OnBnClickedButton1()
{
	e_flag = !e_flag;

	if (e_flag)
	{
		EditOnMode();
	}

	else
	{
		GetDlgItemTextA(IDC_EDIT_NAME, _dog_info.name);
		GetDlgItemTextA(IDC_EDIT_AGE, _dog_info.age);
		GetDlgItemTextA(IDC_EDIT_SPECIES, _dog_info.species);
		GetDlgItemTextA(IDC_EDIT_ADDRESS, _dog_info.address);
		EditOffMode();
	}
	//_edit_age.adjustBorder(true);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}



void Cdogdog191002Dlg::OnBnClickedButton2()
{
	
	if (!e_flag)
	{
		CTestDlg tesss;
		tesss.DoModal();

	}

	else
	{
		e_flag = !e_flag;
		EditOffMode();
	}
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cdogdog191002Dlg::OnBnClickedButtonLoadImg()
{
	CTestDlg testdlg;
	testdlg.DoModal();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void Cdogdog191002Dlg::OnBnClickedButtonOpenCamera()
{
	CTestDlg testdlg;
	testdlg.DoModal();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


