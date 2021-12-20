
// MFCApplication2Dlg.h: 头文件
//

#pragma once
#include <string>


// CMFCApplication2Dlg 对话框
class CMFCApplication2Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication2Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	CStatic m_jzmPicture;
	afx_msg void OnBnClickedButton2();
	CStatic m_jzmPicture2;
	CStatic m_jzmPicture3;
	afx_msg void OnBnClickedButton3();
	CStatic m_jzmPicture4;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnStnClickedJizhuomiStatic3();
	afx_msg void OnBnClickedButton5();
	CString gReadFilePathName;
	CString gReadFilePathName_PART;
	CString gReadFilePathName_NOICE;
	CString gReadFilePathName_BLUR;
	CString gReadFilePathName_EDGE;
	CString gReadFilePathName_CANNY;
	afx_msg void OnCbnSelchangeWebCombo();
	CComboBox m_comboWeb;
	afx_msg
		void threshold(int, void*);
	void OnCbnSelchangeWebCombo7();
	CComboBox m_comboWeb7;
	CComboBox m_comboWeb9;
	afx_msg void OnCbnSelchangeWebCombo9();
	int callBackboxFilter();
	afx_msg void OnEnChangeHscrollEdit();
	CScrollBar m_horiScrollbar;
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar m_horiScrollbar2;
	CScrollBar m_horiScrollbar3;
	afx_msg void OnEnChangeHscrollEdit1();
	afx_msg void OnStnClickedJizhuomiStatic4();
	CStatic m_jzmPicture5;
	afx_msg void OnNMThemeChangedScrollbar3(NMHDR* pNMHDR, LRESULT* pResult);
};
