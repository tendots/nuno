# nuno
Electric fabric touchpad "nüno"
導電布タッチセンサーnünoのコードです。

質問や要望などあればこのページかFacebookページへご連絡ください。
* Facebook page https://www.facebook.com/Project-n%C3%BCno-183796265747425/

## 仕様 ##
* 静電容量タッチセンサ　[mtch6102](https://www.microchip.com/wwwproducts/en/MTCH6102)
* タッチチャンネル数8
* コネクタ GROVEコネクタ(I2C)

## 導線部接続方法
https://user-images.githubusercontent.com/1772744/43694801-1fe4aa3a-9970-11e8-96b2-6911c2a84bb4.JPG

導線部（細長い方）は画像のように、縫い目がセンサー部（四角い方）の外縁に向くように接続してください。
逆につけた取り付けた場合、すべてのチャンネルの値が取得できません。

## フレキシブル基板コネクタ接続方法 ##
https://user-images.githubusercontent.com/1772744/43694897-90800ca8-9970-11e8-9747-4d1033866c79.JPG

フレキシブル基板のコネクタは、リジット基板のFPCコネクタに接続後、
画像のようにフレキシブル基板と布を両方挟み込むようにして、
付属の固定具でネジ止めしてください。


## 付属ケースカット方法 ##

## 参考 ##
[touch_timer](https://github.com/theapi/touch_timer)
