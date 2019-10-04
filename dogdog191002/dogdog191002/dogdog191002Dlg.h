
// dogdog191002Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "TestDlg.h"

typedef struct _Dogdata {
	CString name;
	CString age;
	CString species;
	CString address;
}Dogdata;


// Cdogdog191002Dlg ��ȭ ����
class Cdogdog191002Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Cdogdog191002Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOGDOG191002_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void EditOnMode();
	void EditOffMode();
	

protected:
	CEdit _edit_name;
	CEdit _edit_age;
	CEdit _edit_species;
	CEdit _edit_address;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonLoadImg();
protected:
	CButton _btn_load_image;
	CButton _btn_open_camera;
	afx_msg void OnBnClickedButtonOpenCamera();
	CButton _btn_left;
	CButton _btn_right;
	Dogdata _dog_info;
	bool e_flag;
};
