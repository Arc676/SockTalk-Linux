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

class SockTalkFrontend;

#include <QVariant>
#include "socktalkclient.h"

class Client : public SockTalkClient {
	SockTalkFrontend* frontend;
public:
	using SockTalkClient::SockTalkClient;
	virtual void handleMessage(const std::string &msg, int type, const std::string &src);

	int send(QVariant msg);

	bool connect(QVariant host, int port, QVariant username, QVariant cert, QVariant key);

	void setFrontend(SockTalkFrontend* frontend);
};
