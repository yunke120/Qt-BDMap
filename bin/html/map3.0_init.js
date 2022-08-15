/**
 * 离线API初始化, 请在加载map3.0.js之前引入
 */

/**
 * 这是必须要确认的配置
 * 瓦片图必须是png图像
 */
var bmapConfig = {
  'tiles_path'     : 'tiles',      //显示普通地图，为空默认在 tiles/ 目录
  'tiles_satellite_path': 'tiles_satellite', //显示卫星影像，为空默认在 tiles_satellite/ ，只有底图没有地址标注
  'tiles_hybrid_path'   : 'tiles_hybrid'  //显示带有街道的卫星影像，为空默认在 tiles_hybrid/，需和卫星影像配合使用
};

//获得API主目录，一般不需要修改
var scripts = document.getElementsByTagName("script");
var _JS__FILE__ = scripts[scripts.length - 1].getAttribute("src");
bmapConfig.home_dir = _JS__FILE__.substr(0, _JS__FILE__.lastIndexOf("/"));
if( bmapConfig.tiles_path.length == 0 ){
  bmapConfig.tiles_path = bmapConfig.home_dir + "/tiles";
}
if( bmapConfig.tiles_satellite_path.length == 0 ){
  bmapConfig.tiles_satellite_path = bmapConfig.home_dir + "/tiles_satellite";
}
if( bmapConfig.tiles_hybrid_path.length == 0 ){
  bmapConfig.tiles_hybrid_path = bmapConfig.home_dir + "/tiles_hybird";
}
//调试日志，请保留
function bmapLog(s){
  if(typeof console != 'undefined')
    console.log('>>> '+s);
}
