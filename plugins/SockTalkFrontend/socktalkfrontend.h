// Copyright (C) 2019 Arc676/Alessandro Vinciguerra <alesvinciguerra@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation (version 3)

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#ifndef SOCKTALKFRONTEND_H
#define SOCKTALKFRONTEND_H

#include <QVariant>
#include <QString>
#include <QObject>

#include "client.h"

class SockTalkFrontend: public QObject {
	Q_OBJECT
	Client* client;
public:
	SockTalkFrontend();
	~SockTalkFrontend();

	void handleMessage(const std::string &msg, int type, const std::string &src);

	void wasDisconnected();

	Q_INVOKABLE bool connect(QVariant host, int port, QVariant username, QVariant cert, QVariant pem);
	Q_INVOKABLE bool sendMessage(QVariant msg);
	Q_INVOKABLE bool disconnect();
signals:
	void newMessage(QString msg);
	void connectionChanged(bool connected);
};

#endif
