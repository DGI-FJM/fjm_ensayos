<?php 

class EnsayosPdf {
  protected $pid;
  
  function __construct($pid) {
    $this->pid = $pid;
  }
  
  /**
   * Embed Google Docs' PDF viewer into the page in the FJM way
   * @global type $base_url
   * @global type $base_path
   * @global type $user
   * @return type
   */
  function showPDFPreview_FJM($page = NULL) {
    global $base_url;
    global $base_path;
    module_load_include('inc', 'fedora_repository', 'api/fedora_item');
    module_load_include('inc', 'fedora_repository', 'ObjectHelper');
  
    $tabset = array();

    $item = new Fedora_Item($this->pid);
    $dc_html = fjm_ensayos_render_qdc($this->pid);
    $dl_link = l('<div  style="float:left;">'. t('Download Document').'</div>', 'fedora/repository/' . $this->pid . '/OBJ', array('html' => TRUE));
  
    $tabset['first_tab'] = array(
      '#type' => 'tabpage',
      '#title' => t('Read Online'),
      '#content' => "<iframe src=\"http://docs.google.com/viewer?url=" . $base_url . '/fedora/repository/' .
      $this->pid . '/OBJ/preview.pdf' . "&embedded=TRUE\" style=\"width:500px; height:600px;\" frameborder=\"0\"></iframe> <div id='metadata' style='width:400px; float:left; padding-right:20px'>" . t($dc_html) .$dl_link ."</div>"
    );
  
  
    // Render the tabset.
    return $tabset;
  }
}