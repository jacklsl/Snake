#pragma once


// CHeroDlg 对话框

class CHeroDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHeroDlg)

public:
	void SetWriteFlg(BOOL bflg);
	CHeroDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHeroDlg();

// 对话框数据
	enum { IDD = IDD_HERO_DIALOG };

	int m_level;
	CString m_name;
	int m_score;
public:
	virtual int DoModel();
	
protected:
	virtual void OnOK();
	virtual BOOL OnInitDialog();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bWriteflg;
public:
	afx_msg void OnClickedHeroButton();
};
