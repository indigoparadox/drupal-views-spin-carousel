
<pre>
<?php //print_r( $rows ); ?>
<?php //print_r( $options ); ?>
<?php //print_r( get_defined_vars() ); ?>
<?php print_r( $view->query ); ?>
<?php dpm( $view ); ?>
</pre>
<?php die(); ?>

<div class="iygallery-slides" style="<?php echo( 
   'width: '.$options['size_image']['width'].'px; '.
   'height: '.$options['size_image']['height'].'px'
) ?>">
<?php for( $i = 0 ; $i < count( $rows ) ; $i++ ) { ?>
   <div class="iygallery-slide-content">
      <?php echo( $rows[$i]->field_images['rendered_full'] ); ?>

      <div class="iygallery-slide-content-copy">
      
      <h2 class="iygallery-slide-content-copy-title"><?php
         echo( $rows[$i]->title );
      ?></h2>
      
      <?php if( $options['show_pubdate'] ) { ?>
      <div class="iygallery-slide-content-copy-pubdate">
      <?php echo( format_date( 
         $rows[$i]->created, 'custom', $options['pubdate_format']
      ) ); ?>
      </div>
      <?php } ?>

      <div class="iygallery-slide-content-copy-copy">
      <?php if( !empty( $rows[$i]->summary ) ) {
         echo( $rows[$i]->summary );
      } else {
         echo( $rows[$i]->body );
      } ?>
      </div>

      <div class="iygallery-slide-content-copy-readmore">
      <?php echo( l( t( 'Read more...' ), 'node/'.$rows[$i]->nid ) ); ?>
      </div>
      
      </div>
   </div>

<?php } ?>
</div>

<?php if( $options['show_thumbs'] ) { ?>
<div class="iygallery-thumbs-wrapper">
<a class="iygallery-thumbs-previous" href="#"><?php echo(
   $options['thumbs_previous_label']
); ?></a></li>
<div class="iygallery-thumbs" style="<?php echo( 
   'height: '.$options['size_thumb']['height'].'px'
) ?>">
<div class="iygallery-thumbs-pane">
<? for( $i = 0 ; $i < count( $rows ) ; $i++ ) {

   if( 0 != $i && 0 == $i % $options['thumbs_per_page'] ) {
      echo( '</div><div class="iygallery-thumbs-pane">' );
   }

   echo( l(
      $rows[$i]->field_images['rendered_thumb'],
      '',
      array(
         'attributes' => array(
            // TODO: Add selector to specify which slideshow.
            'onclick' => 'return gallery_goto( \''.$view->name.'\', '.$i.' )',
            'class' => 'iygallery-thumb-link',
         ),
         'html' => true,
      )
   ) );

} ?>
</div>
</div>
<a class="iygallery-thumbs-next" href="#"><?php echo(
   $options['thumbs_next_label']
); ?></a>
</div>
<?php } ?>

