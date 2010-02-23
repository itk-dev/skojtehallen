<?php if (!$field_empty) : ?>
  <?php ((count($items) != 1) ? (print '<div class="repeated-events">') : ('')) ?>
  <div class="field-label">
  <?php
    if (count($items) == 1) {
      print t($label);
    }
    else {
      print t('Click here for event detials');
    }
  ?>
  </div>
  <div class="field field-type-<?php print $field_type_css ?> field-<?php print $field_name_css ?>">
    <div class="field-items">
      <?php $count = 1;
      foreach ($items as $delta => $item) :
        if (!$item['empty']) : ?>
          <div class="field-item <?php print ($count % 2 ? 'odd' : 'even') ?>">
            <?php print $item['view'] ?>
          </div>
        <?php $count++;
        endif;
      endforeach;?>
    </div>
  </div>
  <?php ((count($items) != 1) ? (print '</div>') : ('')) ?>
<?php endif; ?>
