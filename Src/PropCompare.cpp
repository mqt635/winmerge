// PropCompare.cpp : implementation file
//

#include "stdafx.h"
#include "merge.h"
#include "PropCompare.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropCompare property page

IMPLEMENT_DYNCREATE(CPropCompare, CPropertyPage)

CPropCompare::CPropCompare() : CPropertyPage(CPropCompare::IDD)
{
	//{{AFX_DATA_INIT(CPropCompare)
	m_compareMethod = -1;
	m_bIgnoreCase = FALSE;
	m_bIgnoreBlankLines = FALSE;
	m_bEolSensitive = FALSE;
	m_nIgnoreWhite = -1;
	//}}AFX_DATA_INIT
}

CPropCompare::~CPropCompare()
{
}

void CPropCompare::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropCompare)
	DDX_CBIndex(pDX, IDC_COMPAREMETHODCOMBO, m_compareMethod);
	DDX_Check(pDX, IDC_IGNCASE_CHECK, m_bIgnoreCase);
	DDX_Check(pDX, IDC_IGNBLANKS_CHECK, m_bIgnoreBlankLines);
	DDX_Check(pDX, IDC_EOL_SENSITIVE, m_bEolSensitive);
	DDX_Radio(pDX, IDC_WHITESPACE, m_nIgnoreWhite);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropCompare, CPropertyPage)
	//{{AFX_MSG_MAP(CPropCompare)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropCompare message handlers

BOOL CPropCompare::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	CComboBox * combo = (CComboBox*) GetDlgItem(IDC_COMPAREMETHODCOMBO);

	CString item;
	VERIFY(item.LoadString(IDS_COMPMETHOD_CONTENTS));
	combo->AddString(item);
	VERIFY(item.LoadString(IDS_COMPMETHOD_MODDATE));
	combo->AddString(item);
	combo->SetCurSel(m_compareMethod);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
