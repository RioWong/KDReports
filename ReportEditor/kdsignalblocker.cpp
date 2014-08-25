/****************************************************************************
** Copyright (C) 2007-2014 Klaralvdalens Datakonsult AB.  All rights reserved.
**
** This file is part of the KD Reports library.
**
** Licensees holding valid commercial KD Reports licenses may use this file in
** accordance with the KD Reports Commercial License Agreement provided with
** the Software.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU Lesser General Public License version 2.1 and version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE.LGPL.txt included.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** Contact info@kdab.com if any conditions of this licensing are not
** clear to you.
**
**********************************************************************/

#include "kdsignalblocker.h"

#include <QObject>

/*!
  \class KDSignalBlocker
  \ingroup raii core
  \brief Exception-safe and convenient wrapper around QObject::blockSignals()

  All methods in this class are nothrow if QObject::blockSignals() and
  QObject::signalsBlocked() are nothrow, which they normally are.
*/


/*!
  Constructor. Blocks signals on \a o.

  \post o->signalsBlocked() == true
*/
KDSignalBlocker::KDSignalBlocker( QObject * o )
    : blocked( o->signalsBlocked() ), object( o )
{
    o->blockSignals( true );
}

/*!
  Destructor. Unblocks signals (unless they were blocked before)

  \post o->signalsBlocked() is the same as just before this instance has been constructed.
*/
KDSignalBlocker::~KDSignalBlocker() {
    object->blockSignals( blocked );
}
