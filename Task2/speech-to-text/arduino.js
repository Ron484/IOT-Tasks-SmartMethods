let isConnected = false;
let port;
let writer;

const enc= new TextEncoder();



async function onSpeech() {
    if (!isConnectted) {
      alert("you must connect to the usb in order to use this.");
      return;
    }
  
    try {
      await writer.write(enc.encode(computerText));
    } catch (e) {
      console.log(e);
    }
  }
async function onConnectUsb(){
    try{
        const requestOptions ={
            filters: [ {usbVendorId: 0x2341}] ,
        };

        port = await navigator.serial.requestPort(requestOptions);
        await port.open({buadrate: 115200});
        writer= port.writeable.getWriter();
        isConnected = true;
    }
    catch (e){
    console.log("err", e);
    }
}

