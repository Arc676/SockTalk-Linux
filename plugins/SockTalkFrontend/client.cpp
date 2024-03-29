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

#include "socktalkfrontend.h"

void Client::handleMessage(const std::string &msg, int type, const std::string &src) {
	if (status == FORCIBLY_DISCONNECTED) {
		return;
	}
	if (frontend) {
		frontend->handleMessage(msg, type, src);
	}
	if (!msg.compare(0, 6, "TERM: ")) {
		status = FORCIBLY_DISCONNECTED;
		frontend->wasDisconnected();
	}
}

int Client::send(QVariant msg) {
	return SockTalkClient::send(msg.toString().toStdString());
}

void Client::setFrontend(SockTalkFrontend* frontend) {
	this->frontend = frontend;
}

bool Client::connect(QVariant host, int port, QVariant username, QVariant cert, QVariant key) {
	initialize(
		port,
		host.toString().toStdString(),
		username.toString().toStdString(),
		cert.toString().toStdString(),
		key.toString().toStdString()
	);
	return status == SUCCESS;
}
