# Dog Biometrics Project

## test update

-2019.10.24������ ����Ʈ ��Ȳ

1. DogRegister::Checkarg() �߰�
	�̸�,�?�ּ�,���� �����?����
	���� ���?����� ����(���ڸ��� �ٸ��� �ĵ� ����)

2. CameraMgr.cpp �� �ڵ��߰�
	CameraMgr::OnBnClickedOk() �� CameraMgr::OnBnClickedCancel()�� �ڵ��߰�
	

	�߰��� �ڵ�:

		if (capture)
		{
			delete capture;
		}
	�߰��� ���?
		���ϸ� ī�޶� �Ȳ��� -> �Ȳ����?�����?�ٽ� ����Ϸ�� ������ MFC�� ����

3-1. stdafx.h�� #define���?SAVE_PATH�� IMAGE_PATH �߰�
	�������?��ǻ�� C:\DogIdentificationdn�� ���?�����?�̹����?C:\DogIdentification\Image �� �����Ϸ��?
	IMAGE_PATH�� �����?"Image"�� �ߴµ� �׳� " C:\DogIdentification\Image"�� �ٲܱ� �����?3-3���?


3-2. DogIdentificationDlg.cpp�� SAVE_PATH�� ���?�����?�����?�ڵ� ���?
	�����?�����ϸ�, ���?�����?���� �Ŀ� �����?���?���� �� ���?

3-3. DogResister.cpp�� Image ���?�����?�����?CImage�̿��ؼ� ���� ���?�����ϴ� �ڵ� ���?4�� ����)
	�̶� ���?���?�Ҷ�  SAVE_PATH�� IMAGE_PATH �� ���ļ� ����ϴµ�?�׳� IMAGE_PATH �ϳ��� �� �� �ְ� IMAGE_PATH ��ü�� �ٲܱ� �����?
	���� �����Ҷ� ���� �̸��?������ �̸�,
		�̶� ���?�̸��� ������ �̹� �ִٸ� �̸�_����, �� ����
		���ڴ� ����̸���?������ �Ѹ��� ���������?�þ.

4. CameraMgr.h�� CStatic* m_picDog �߰��ϰ� DogResister.cpp ���� open camera��ư ������ m_bmpBitmap�̶� ������Ŵ (�̹��� �����ϱ� ���?
	DogRegister::OnBnClickedBtnOpencamera() ���� pCameraInst->save_img = &m_bmpBitmap; �� ����
	CameraMgr::OnBnClickedOk() �κп��� save_img�� ���� ����

5. CameraMgr::OnBnClickedOk()���� StretchDIBits�Լ� ���?
	������ Ʋ�����?���� �Ǳ淡 ���� �ʺ� �����? �� �ڵ尡 �����?���� ����
	StretchDIBits(cimage_mfc.GetDC(), 0, 0, rect.Width(), rect.Height(), 0, 0, imgWidth, imgHeight, mat_temp.data, bitInfo, DIB_RGB_COLORS, SRCCOPY); ����
	imgWidth, imgHeight �κи� �ٲ�



=======

# [MFC]

## 마친 ??
- UserPassword(?�료)
	- ?�?�된 ?�스?�드가 ?�을 ???�스?�드 ?�록 창으�??�어가???�스?�드 ?�록
- Login(?�료) 
	- ?�?�된 ?�스?�드가 ?�을 ??로그??창으�??�어가???�스?�드 비교??로그??

- EditPassword(?�료)
	- ?�스?�드 체크
	- ?�스?�드 변�??? 변�??�스?�드 ?�??

~~~
?�스?�드 ?�일???�?�경로는 my_define.h ?�일??명시?�어 ?�다. 
~~~
- CamerMgr(?�료)
	- ?�진찍기

- DogRegister(부분완�?
	- local?�서 ?��?지 불러?�기
	- webcam?�서 ?�진 찍어 ?�우�?CameraMgr?�서 찍�? ?�진 받아???��?)
	- db??강아지 ?�보 ?�록(?��?지 ?�외??모든 ?�보)

- SearchDogInfo(부분완�?
	- local?�서 ?��?지 불러?�기
	- webcam?�서 ?�진 찍어 ?�우�?CameraMgr?�서 찍�? ?�진 받아???��?)
	- 강아지?�보 Search( ?�재???��?지검?�이 ?�되므�?db???�일 마�?막에 ?�록?�어?�는 강아지 ?�보 불러??
	- 강아지?�보 변�?& db???�??
	- 강아지?�보 ??��

## ?�야????
- DogRegister
	- ?��?지 분석 & 분석?�보 받아?�기
	- 분석???��?지가 기존??존재?�는 강아지 ?�보?��? Search
	- ?��?지 분석?�보 ?�??

- SearchDogInfo
	- ?��?지 검?�해??강아지 ?�보 받아?�기

- 창닫�?버튼 비활?�화

- memory leak ?�결


# [RaceCar]




-2019.10.24 ���ı����� ������Ʈ ��Ȳ

1. CateraMgr.cpp �� void CameraMgr::OnBnClickedOk()���� �߸��� DC�� Release �ǰ��ֱ⿡ ������.
	::ReleaseDC(m_camerapic->m_hWnd, dc);  ���� ::ReleaseDC(m_picDog->m_hWnd, dc); �� ����

2. DbAccess�� Image_path�� ���õ� �κе� �߰�

3. SearchDogInfo�� search/edit/delete ��� �߰�
	
	search -> ������ �ϴ��� ���� �������� ����� ������ ã�´�.
		   -> �̹��� ������ �̹����� ���ٴ� �˸�â�� ���.

	edit   -> ������ ������ �ϴ� ����Ǿ��ִ� ���� ������ �����, ���� ������ �̸����� �ٽ� �����Ѵ�. (����� dogRegister�� ����)
		   -> DbAccess::DbSetting(m_dogName, m_dogAge, m_gender, m_dogSpecies, m_dogAddr, file_name); ���� �������� file_name�� ������ ���ο� ��� �����Ϸ���.
		   -> edit �Ҷ� �̻��� ���� �����°� ���� ���� DogRegister�� �ִ� Checkarg()�Լ� ������ -> �ٵ� '���� ���� �ִ°��� ���ƾ� �Ѵ�,,,, db�� ���� �� ������...

	delete -> ���� ������ ������ ������ �����, db_table���� ������ �� �����.
		   -> ���� �Ŀ��� ȭ�� �ʱ�ȭ (Invalidate(true); ���)



-2019.10.28 3:30  ������ ������Ʈ ��Ȳ

1. ����� ��й�ȣ C����̺꿡 ���� ������ ���� �����ؼ� ����� �� �� �ְ� ����
2. �α���â���� �α���â x ������ ���� �α��� ����â���� �Ѿ�淡 xǥ ������ MFC ���α׷��� ����ǰ� ����


