#pragma once
#include "afxwin.h"


// UserPassword ��ȭ �����Դϴ�.

class UserPassword : public CDialogEx
{
	DECLARE_DYNAMIC(UserPassword)

public:
	UserPassword(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~UserPassword();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PASSWORD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
    CEdit m_editPassword1;
    CEdit m_editPassword2;

    CString GetPassword();
private:
    CString m_strPassword;
public:
    afx_msg void OnBnClickedOk();
};
