/** 
 *  Copyright (c) 1999~2017, Altibase Corp. and/or its affiliates. All rights reserved.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License, version 3,
 *  as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 

/***********************************************************************
 * $Id: smpFT.h 19550 2007-02-07 03:09:40Z kimmkeun $
 **********************************************************************/

#ifndef _O_SMP_FT_H_
#define _O_SMP_FT_H_  (1)

# include <idu.h>
# include <smDef.h>
# include <sdcDef.h>

/* ���� Varchar�� 32000���� �����ϴ�. ����, 
 * Page�ϳ��� ���� Dump�ϱ⿡�� ������� �ʱ�
 * ������, 8192Byte��Dump�Ѵ�. */

#define SMP_PAGE_PART_SIZE       (8192)
#define SMP_DUMP_COLUMN_SIZE     ((SMP_PAGE_PART_SIZE*2) + 8)

//----------------------------------------
// D$MEM_DB_PAGE
//----------------------------------------- 
// 32k / 8k = 4
typedef struct smpMemDBPageDump
{
    scSpaceID mTBSID;
    scPageID  mPID;
    SChar     mPageDump1[SMP_DUMP_COLUMN_SIZE];
    SChar     mPageDump2[SMP_DUMP_COLUMN_SIZE];
    SChar     mPageDump3[SMP_DUMP_COLUMN_SIZE];
    SChar     mPageDump4[SMP_DUMP_COLUMN_SIZE];
} smpMemDBPageDump;


class smpFT
{
public:
    //------------------------------------------
    // D$MEM_DB_PAGE
    // MEM PCH�κ��� �������� Dump�Ѵ�.
    //------------------------------------------
    static IDE_RC buildRecordMemDBPageDump(idvSQL              * /*aStatistics*/,
                                           void                *aHeader,
                                           void                *aDumpObj,
                                           iduFixedTableMemory *aMemory);
};

#endif /* _O_SMP_FT_H_ */