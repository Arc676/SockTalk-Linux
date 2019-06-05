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

SockTalkFrontend::SockTalkFrontend() {
	client = new Client();
}

SockTalkFrontend::~SockTalkFrontend() {
	delete client;
}

bool SockTalkFrontend::sendMessage(QVariant msg) {
	return client->send(msg) == msg.toString().length();
}

bool SockTalkFrontend::connect(QVariant host, int port, QVariant username, QVariant cert, QVariant pem) {
	return client->connect(host, port, username, cert, pem);
}

bool SockTalkFrontend::disconnect() {
	client->closeClient();
	return true;
}

void SockTalkFrontend::handleMessage(const std::string &msg, int type, const std::string &src) {
	emit newMessage(QString::fromStdString(msg));
}

void SockTalkFrontend::wasDisconnected() {
	emit connectionChanged(false);
}
