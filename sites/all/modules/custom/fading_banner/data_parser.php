<?php

include_once 'fading_banner.module';

class DataParser {

  private $type = NULL;
  private $file = NULL;
  private $xml = NULL;

  public function  __construct($type) {
    $this->type = $type;
    switch ($type) {
      case FADING_BANNER_SKOJTEHAL:
        $this->file = drupal_get_path('module', 'fading_banner'). '/' .FADING_BANNER_SKOJTEHAL. '.xml';
        break;

      case FADING_BANNER_ICE:
        $this->file = drupal_get_path('module', 'fading_banner'). '/' .FADING_BANNER_ICE. '.xml';
        break;
    }
    $this->load();
  }

  public function __destruct() {
    $this->save();
  }

  private function load() {
    $this->xml = new DOMDocument('1.0', 'utf-8');
    $this->xml->load($this->file);
  }

  private function save() {
    $this->xml->formatOuput = TRUE;
    $this->xml->save($this->file);
  }

  public function addBanner($image) {
    $banner = $this->xml->createElement('img');
    $banner->appendChild($this->xml->createTextNode('/' .$image['filepath']));
    $root = $this->xml->getElementsByTagName('data');
    foreach ($root as $r) {
      $r->appendChild($banner);
    }
  }

  public function removeBanner($image) {
    $xp = new DOMXPath($this->xml);
    $nodes = $xp->query('//img');
    foreach ($nodes as $node) {
      if ($node->nodeValue == '/'. $image['filepath']) {
        $node->parentNode->removeChild($node);
      }
    }
  }

  public function updateBanner($image) {
    if ($this->type == FADING_BANNER_SKOJTEHAL) {
      $other_type = new DataParser(FADING_BANNER_ICE);
    }
    else {
      $other_type = new DataParser(FADING_BANNER_SKOJTEHAL);
    }
    $other_type->removeBanner($image); // It may not exists in the other, but we do not known..
    $this->removeBanner($image);
    $this->addBanner($image);
  }
}
