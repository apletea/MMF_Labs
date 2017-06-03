import { NgModule, ErrorHandler } from '@angular/core';
import { IonicApp, IonicModule, IonicErrorHandler } from 'ionic-angular';
import { BrowserModule } from '@angular/platform-browser';
import { MyApp } from './app.component';
import { HomePage } from '../pages/home/home';
import { File } from '@ionic-native/file';
import { Camera } from '@ionic-native/camera';
import { Dialogs } from '@ionic-native/dialogs';

@NgModule({
  declarations: [
    MyApp,
    HomePage
  ],
  imports: [
    IonicModule.forRoot(MyApp),
    BrowserModule
  ],
  bootstrap: [IonicApp],
  entryComponents: [
    MyApp,
    HomePage
  ],
  providers: [{provide: ErrorHandler, useClass: IonicErrorHandler}, File, Camera, Dialogs]
})
export class AppModule {}
