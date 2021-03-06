/*
Project: MyCuteAssistant
File: Character.hpp

Copyright (c) 2014, Christoph "Youka" Spanknebel

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

	The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
	Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
	This notice may not be removed or altered from any source distribution.
*/

#pragma once

#include <QtCore/QStringList>
#include <QtGui/QMovie>
#include <QtGui/QPixmap>

namespace MCA{
	class Character{
		public:
			static QStringList possibleNames(void);
			struct Bubble{
				double x = 0, y = 0;
				QPixmap pixmap;
				double edit_x = 0, edit_y = 0, edit_width = 0.5, edit_height = 0.1;
			};
			enum class State{IDLE, MOVE};
		private:
			QString id, error;
			QMovie idle, move, null;
			Bubble m_bubble;
			State m_state = State::IDLE;
		public:
			Character(void) = default;
			Character(QString name);
			bool load(QString name);
			QString name(void) const;
			State state(void) const;
			void state(State current);
			QMovie& currentImage(void);
			Bubble& bubble(void);
			QString errorString(void) const;
	};
}
