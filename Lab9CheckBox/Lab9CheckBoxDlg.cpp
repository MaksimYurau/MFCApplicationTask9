
// Lab9CheckBoxDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "Lab9CheckBox.h"
#include "Lab9CheckBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CLab9CheckBoxDlg



CLab9CheckBoxDlg::CLab9CheckBoxDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LAB9CHECKBOX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLab9CheckBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLab9CheckBoxDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECKBOX_NECHET, &CLab9CheckBoxDlg::OnBnClickedCheckboxNechet)
	ON_BN_CLICKED(IDC_CHECKBOX_CHET, &CLab9CheckBoxDlg::OnBnClickedCheckboxChet)
	ON_BN_CLICKED(IDC_CHECKBOX_NECHET_VALUE, &CLab9CheckBoxDlg::OnBnClickedCheckboxNechetValue)
	ON_BN_CLICKED(IDC_CHECKBOX_CHET_VALUE, &CLab9CheckBoxDlg::OnBnClickedCheckboxChetValue)
END_MESSAGE_MAP()


// Обработчики сообщений CLab9CheckBoxDlg

BOOL CLab9CheckBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	CDialog::OnInitDialog();

	// Получаем указатель на список LISTBOX_MAIN
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LISTBOX_MAIN);

	// Заполняем список 100 случайными числами
	srand((unsigned int)time(NULL)); // Инициализируем генератор случайных чисел

	for (int i = 0; i < 100; i++)
	{
		int randomNumber = rand(); // Генерируем случайное число
		CString strNumber;
		strNumber.Format(_T("%d"), randomNumber); // Преобразуем число в строку
		pListBox->AddString(strNumber); // Добавляем строку в список
	}
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLab9CheckBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CLab9CheckBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLab9CheckBoxDlg::OnBnClickedCheckboxNechet()
{
	BOOL bChecked = ((CButton*)GetDlgItem(IDC_CHECKBOX_NECHET))->GetCheck();

	// Получаем указатель на список LISTBOX_MAIN
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LISTBOX_MAIN);

	// Выделяем/снимаем выделение для четных строк
	for (int i = 0; i < pListBox->GetCount(); i++)
	{
		// Проверяем, является ли индекс строки четным
		if (i % 2 != 0)
		{
			// Выделяем или снимаем выделение в зависимости от состояния флажка
			if (bChecked)
				pListBox->SetSel(i, TRUE);
			else
				pListBox->SetSel(i, FALSE);
		}
	}
}


void CLab9CheckBoxDlg::OnBnClickedCheckboxChet()
{

		// Получаем состояние флажка CHECKBOX_CHET
		BOOL bChecked = ((CButton*)GetDlgItem(IDC_CHECKBOX_CHET))->GetCheck();

		// Получаем указатель на список LISTBOX_MAIN
		CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LISTBOX_MAIN);

		// Выделяем/снимаем выделение для четных строк
		for (int i = 0; i < pListBox->GetCount(); i++)
		{
			// Проверяем, является ли индекс строки четным
			if (i % 2 == 0)
			{
				// Выделяем или снимаем выделение в зависимости от состояния флажка
				if (bChecked)
					pListBox->SetSel(i, TRUE);
				else
					pListBox->SetSel(i, FALSE);
			}
		}
	
}


void CLab9CheckBoxDlg::OnBnClickedCheckboxNechetValue()
{
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LISTBOX_MAIN);

	// Очищаем текущее выделение
	pListBox->SetSel(-1, FALSE);

	// Выделяем четные значения
	for (int i = 0; i < pListBox->GetCount(); i++)
	{
		CString strValue;
		pListBox->GetText(i, strValue); // Получаем значение строки

		int value = _ttoi(strValue); // Преобразуем строку в число

		if (value % 2 == 1)
		{
			pListBox->SetSel(i, TRUE); // Выделяем строку
		}
	}
}


void CLab9CheckBoxDlg::OnBnClickedCheckboxChetValue()
{
	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LISTBOX_MAIN);

	// Очищаем текущее выделение
	pListBox->SetSel(-1, FALSE);

	// Выделяем четные значения
	for (int i = 0; i < pListBox->GetCount(); i++)
	{
		CString strValue;
		pListBox->GetText(i, strValue); // Получаем значение строки

		int value = _ttoi(strValue); // Преобразуем строку в число

		if (value % 2 == 0)
		{
			pListBox->SetSel(i, TRUE); // Выделяем строку
		}
	}
}
