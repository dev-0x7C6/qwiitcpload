/***************************************************************************
 *   Copyright (C) 2008 by Bartlomiej Burdukiewicz                         *
 *   strikeu@poczta.linux.pl                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "ui_mainform.h"
#include "threads.h"
#include "about.h"


#include <QMessageBox>
#include <QFileDialog>
#include <QTextCodec>
#include <QTcpSocket>

using namespace Ui;

class QDialog;
class QThread;
class QWidget;

const QString mainWindowTitle = "WiiTCPLoadGUI v0.02d";

class MainForm: public QMainWindow
{
Q_OBJECT
 private:
   QFileDialog *FileDialog;
   QNetworkThread networkThread;
   QStreamThread nstreamThread;
   void defaultProgressBar(bool enabled, int max, int min, int value);
   void setReadyMode();
   void setCancelMode();

 public:
   mainform ui;
   MainForm(QWidget * parent = 0, Qt::WFlags f = 0 );
   ~MainForm();

 private slots:
   void onConnected(QTcpSocket *socket);
   void onError(QString error);
   void onState(QAbstractSocket::SocketState value);
   void slotDone();
   void slotFail();

 public slots:
   void progressSetup(bool enabled, int max, int min, int value);
   void progressValue(int value);
   void statusMessage(QString msg){ ui.statusLabel->setText(msg); };
// Form
   void slotReadyBtnClicked();
   void slotOpenFileClicked();
// Thread
// MainMenu
   void slotAboutProgram();
   void slotActionExit();
};
