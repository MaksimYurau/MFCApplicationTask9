
// Lab9CheckBoxDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CLab9CheckBoxDlg
class CLab9CheckBoxDlg : public CDialogEx
{
// Создание
public:
	CLab9CheckBoxDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB9CHECKBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckboxNechet();
	afx_msg void OnBnClickedCheckboxChet();
	afx_msg void OnBnClickedCheckboxNechetValue();
	afx_msg void OnBnClickedCheckboxChetValue();
};
