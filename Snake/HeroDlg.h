#pragma once


// CHeroDlg �Ի���

class CHeroDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHeroDlg)

public:
	void SetWriteFlg(BOOL bflg);
	CHeroDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CHeroDlg();

// �Ի�������
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bWriteflg;
public:
	afx_msg void OnClickedHeroButton();
};
