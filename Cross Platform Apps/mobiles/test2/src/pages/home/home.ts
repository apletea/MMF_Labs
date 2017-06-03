import { Component } from '@angular/core';
import { File } from '@ionic-native/file';
import { Platform} from 'ionic-angular';
import {Camera, CameraOptions} from '@ionic-native/camera';
import { Dialogs } from '@ionic-native/dialogs';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {
  sliderOptions = {
    pager: false,
    //onlyExternal: true
  }
  //s: string;

  fn: string;
  ln: string;
  fd: string;
  str;

  obj = {
   'items': []
  }

  public shotURI: string;
  public options: CameraOptions;

  //pd: number;
  name: string;
  surname: string;

  constructor(public file: File, public plt:Platform, public camera: Camera, public dlg: Dialogs) {
    this.options={
      quality:100,
      destinationType: camera.DestinationType.FILE_URI,
      targetWidth: 1000,
      targetHeight: 1000,
      saveToPhotoAlbum: true,
      encodingType: camera.EncodingType.JPEG
    }
    //this.obj.items.push({ 'fn': 'экранЕ', 'ln': 'hello', 'fd': 'gggg' });

    //this.pd = 0;
    this.name="";
    this.surname="";

    plt.ready().then(()=>this.onReady());

  }

onReady(){
    this.file.checkFile(this.file.dataDirectory,"myfile.txt").then(result=>
        {if(!result){
                this.file.createFile(this.file.dataDirectory,"myfile.txt",true).then(()=>
                this.file.writeExistingFile(this.file.dataDirectory,"myfile.txt",JSON.stringify(this.obj)));
        }
        else{
            this.file.readAsText(this.file.dataDirectory,"myfile.txt").then(data=>this.obj=JSON.parse(data));
        }

        }
    )
}


  onAdd() {
      //this.inf.fn = this.fn;
      //this.inf.ln = this.ln;
      //this.inf.fd = this.fd;
      this.str = {
        'fn': this.name,
        'ln': this.surname,
        'shotURI': this.shotURI
      };
      this.obj.items.push(this.str);
  }

    onDelete(index: number) {
        this.obj.items.splice(index, 1);
    }
    onWrite(){
        this.file.writeExistingFile(this.file.dataDirectory,"myfile.txt",JSON.stringify(this.obj));
    }

    onRead(){
      this.file.readAsText(this.file.dataDirectory,"myfile.txt").then(data=>this.obj=JSON.parse(data));
    }

  takePic(){
    this.camera.getPicture(this.options).then(imageuri=>this.shotURI=imageuri);
  }
  showPic(){
    this.camera.getPicture({
      quality:100,
      destinationType: this.camera.DestinationType.FILE_URI,
      targetWidth:1000,
      targetHeight:1000,
      sourceType:2,
      encodingType: this.camera.EncodingType.JPEG
    }).then(imageuri=>this.shotURI=imageuri);
  }

  show_prompt(){
    this.dlg.prompt("Введите имя","Name request",["Ok","Cancel"],
      "").then(data=>{this.name=data.input1;/*this.pd=data.buttonIndex*/});
    this.dlg.prompt("Enter surname", "Surname req",["Ok","Cancel"],"").then(
      data=>{this.surname=data.input1;}
    );
  }

}
class Info{
  fn: string;
  ln: string;
  fd: string;
}
