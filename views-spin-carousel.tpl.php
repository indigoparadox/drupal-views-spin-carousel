
<?php if( !is_array( $options['front_fields'] ) ) {
   $front_fields = explode( ' ', $options['front_fields'] );
} else {
   $front_fields = array();
} 
?>

<?php

function views_spin_carousel_render_field( $field_key, $field_config, $row ) {
   // TODO: Handle other handlers.
   // TODO: Handle rewritten fields.
   /* print_r( $field_key );
   echo( '<pre>' );
   print_r( $row );
   echo( '</pre>' ); */
   if( 'node' == $field_config->table ) {
      $field_data_key = 'node_'.$field_key;
      echo( '<h3 class="node-title">'.$row->{$field_data_key}.'</h3>' );
   } else {
      $field_data_key = 'field_'.$field_key;
      if( !empty( $field_config->options['element_wrapper_type'] ) ) {
         // Add the wrapper element.
         echo(
            '<'.$field_config->options['element_wrapper_type'].' class="'.
            $field_config->options['element_wrapper_class'].'">'
         );
      }
      echo( drupal_render( $row->{$field_data_key}[0]['rendered'] ) );
      if( !empty( $field_config->options['element_wrapper_type'] ) ) {
         // Add the wrapper element.
         echo(
            '</'.$field_config->options['element_wrapper_type'].'>'
         );
      }
   }
}

?>

<div class="views-spin-carousel-degrade">
For the best experience, please use a modern web browser such as <a href="https://www.mozilla.org/en-US/firefox">Firefox</a> or <a href="https://www.google.com/chrome/">Google Chrome</a>. If you <em>are</em> using a modern browser, then it is possible that your browser does not support 3D acceleration with your current hardware.
</div>
<div class="views-spin-carousel-container">
<div class="views-spin-carousel">
<?php for( $i = 0 ; $i < count( $rows ) ; $i++ ) { ?>
   <div class="views-spin-carousel-panel">
   <div class="views-spin-carousel-flipper">
   <div class="views-spin-carousel-flipper-front">
   <?php foreach( $view->field as $field_key => $field_config ) { ?>
      <?php if( in_array( $field_key, $front_fields ) ) {
         views_spin_carousel_render_field(
            $field_key, $field_config, $rows[$i]
         );
      } ?>
   <?php } ?>
   </div>
   <div class="views-spin-carousel-flipper-back">
   <?php foreach( $view->field as $field_key => $field_config ) { ?>
      <?php if( !in_array( $field_key, $front_fields ) ) {
         views_spin_carousel_render_field(
            $field_key, $field_config, $rows[$i]
         );
      } ?>
   <?php } ?>
   </div>
   </div>
   </div>
<?php } ?>
</div>
</div>

