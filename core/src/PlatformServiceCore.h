/*
 * PlatformServiceCore.h - declaration of PlatformServiceCore class
 *
 * Copyright (c) 2018-2020 Tobias Junghans <tobydox@veyon.io>
 *
 * This file is part of Veyon - https://veyon.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#pragma once

#include "VeyonCore.h"

// clazy:excludeall=copyable-polymorphic

class VEYON_CORE_EXPORT PlatformServiceCore
{
public:
	using SessionId = int;

	static constexpr SessionId SessionIdInvalid = -1;
	static constexpr SessionId SessionIdMax = 99;
	static constexpr auto MaximumSessionCount = SessionIdMax+1;

	PlatformServiceCore();

	SessionId openSession( const QVariant& sessionData );
	void closeSession( SessionId sessionId );

	QVariant sessionDataFromId( SessionId sessionId ) const;
	SessionId sessionIdFromData( const QVariant& data ) const;

	bool multiSession() const
	{
		return m_multiSession;
	}

private:
	QMap<SessionId, QVariant> m_sessions;
	bool m_multiSession;

};
