// SlideInfo.h: interface for the SlideInfo class.
//
//////////////////////////////////////////////////////////////////////

#ifdef INFO_BUILDER

#if !defined(AFX_SLIDEINFO_H__4DEEE415_8F00_411D_8EDF_3AC277D1DC4C__INCLUDED_)
#define AFX_SLIDEINFO_H__4DEEE415_8F00_411D_8EDF_3AC277D1DC4C__INCLUDED_

#include "interface.h"

#pragma once

namespace info
{
    SmartPointer(SlideInfo);
    class SlideInfo : public InfoFile
    {
    public:
        static SlideInfoPtr MakeInfo(const std::wstring& filename);
        virtual ~SlideInfo();

    protected:
        virtual bool isopenfile();
        virtual void clear();

    public:
        const wchar_t* GetData(int level, int index);

    private:
        bool OpenFile(const std::wstring& filename);
        SlideInfo(const std::wstring& filename);

    private:
        typedef std::map<int, Script_Silde>		SildeMAP;

    private:
        bool				m_IsOpenFile;
        SildeMAP			m_info;
    };
};

inline
bool info::SlideInfo::isopenfile()
{
    return m_IsOpenFile;
}

inline
void info::SlideInfo::clear()
{
}

inline
const wchar_t* info::SlideInfo::GetData(int level, int index)
{
    info::SlideInfo::SildeMAP::iterator iter = m_info.find(level);
    if (iter != m_info.end()) {
        Script_Silde datalist = (*iter).second;
        if (index < datalist.Sildelist.size())
            return datalist.Sildelist[index];
    }
    assert(0);
    return NULL;
}

#endif // !defined(AFX_SLIDEINFO_H__4DEEE415_8F00_411D_8EDF_3AC277D1DC4C__INCLUDED_)

#endif //INFO_BUILDER