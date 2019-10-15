// UserPassword.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "TestCode.h"
#include "UserPassword.h"
#include "afxdialogex.h"


// UserPassword ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(UserPassword, CDialogEx)

UserPassword::UserPassword(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_PASSWORD, pParent)
{

}

UserPassword::~UserPassword()
{
}

void UserPassword::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT_PW1, m_editPassword1);
    DDX_Control(pDX, IDC_EDIT_PW2, m_editPassword2);
}


BEGIN_MESSAGE_MAP(UserPassword, CDialogEx)
    ON_BN_CLICKED(IDOK, &UserPassword::OnBnClickedOk)
END_MESSAGE_MAP()


// UserPassword �޽��� ó�����Դϴ�.
CString UserPassword::GetPassword()
{
    return m_strPassword;
}

void UserPassword::OnBnClickedOk()
{
    // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
    CDialogEx::OnOK();
    ///< get password1
    ///< get password2
    ///< compare password1 with password2
    m_editPassword1.GetWindowTextA(m_strPassword);

}
