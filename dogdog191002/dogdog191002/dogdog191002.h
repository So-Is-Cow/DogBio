
// dogdog191002.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// Cdogdog191002App:
// �� Ŭ������ ������ ���ؼ��� dogdog191002.cpp�� �����Ͻʽÿ�.
//

class Cdogdog191002App : public CWinApp
{
public:
	Cdogdog191002App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern Cdogdog191002App theApp;