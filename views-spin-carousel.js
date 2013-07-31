
var quartzIrisCarouselTheta = 0;

jQuery(document).ready( function() {
   if( Modernizr.csstransforms3d ) {
      // Only activate our fancy carousel if the browser can do 3D.
      jQuery( Drupal.settings.quartzIris.portfolioCarousel.containerClass )
         .addClass( 'portfolio-carousel-container' );
      jQuery( Drupal.settings.quartzIris.portfolioCarousel.carouselClass )
         .addClass( 'portfolio-carousel' );
      jQuery( Drupal.settings.quartzIris.portfolioCarousel.panelClass )
         .addClass( 'portfolio-carousel-panel' );
      
      jQuery( Drupal.settings.quartzIris.portfolioCarousel.flipperClass )
         .addClass( 'portfolio-flipper' );
         /* .addClass( 'animated flipInX' )
         .removeClass( 'flipInX animated' ); */
      jQuery( Drupal.settings.quartzIris.portfolioCarousel.flipperFrontClass )
         .addClass( 'portfolio-flip-front' );
      jQuery( Drupal.settings.quartzIris.portfolioCarousel.flipperBackClass )
         .addClass( 'portfolio-flip-back' );

      //jQuery( Drupal.settings.quartzIris.portfolioCarousel.containerClass )
      jQuery( '#content' ).append(
         '<a href="#" class="portfolio-carousel-link animated flipInX" ' +
            'id="portfolio-carousel-link-previous" ' +
            'onClick="return quartzIrisCarouselPrevious()">Previous</a>'
      );
      jQuery( '#content' ).append(
         '<a href="#" class="portfolio-carousel-link animated flipInX" ' +
            'id="portfolio-carousel-link-next" ' +
            'onClick="return quartzIrisCarouselNext()">Next</a>'
      );
   }
} );

function quartzIrisCarouselPrevious() {
   // Calculate the transformation angle.
   if( 0 > quartzIrisCarouselTheta ) {
      quartzIrisCarouselTheta = 360;
   } else {
      quartzIrisCarouselTheta -=
         Drupal.settings.quartzIris.portfolioCarousel.tiltInc;
   }

   // Apply the transformation.
   jQuery( Drupal.settings.quartzIris.portfolioCarousel.carouselClass ).
      css(
         'transform',
         'translateZ( ' + 
            //Drupal.settings.quartzIris.portfolioCarousel.tiltZ.toString() +
            '0px ) rotateY( ' +
            quartzIrisCarouselTheta.toString() +
            'deg )'
      );
   jQuery( Drupal.settings.quartzIris.portfolioCarousel.carouselClass ).
      css(
         '-moz-transform',
         'translateZ( ' + 
            //Drupal.settings.quartzIris.portfolioCarousel.tiltZ.toString() +
            '0px ) rotateY( ' +
            quartzIrisCarouselTheta.toString() +
            'deg )'
      );
   jQuery( Drupal.settings.quartzIris.portfolioCarousel.carouselClass ).
      css(
         '-webkit-transform',
         'translateZ( ' + 
            //Drupal.settings.quartzIris.portfolioCarousel.tiltZ.toString() +
            '0px ) rotateY( ' +
            quartzIrisCarouselTheta.toString() +
            'deg )'
      );

   return false;
}

function quartzIrisCarouselNext() {
   // Calculate the transformation angle.
   if( 360 < quartzIrisCarouselTheta ) {
      quartzIrisCarouselTheta = 0;
   } else {
      quartzIrisCarouselTheta +=
         Drupal.settings.quartzIris.portfolioCarousel.tiltInc;
   }

   // Apply the transformation.
   jQuery( Drupal.settings.quartzIris.portfolioCarousel.carouselClass ).
      css(
         'transform',
         'translateZ( ' + 
            //Drupal.settings.quartzIris.portfolioCarousel.tiltZ.toString() +
            '0px ) rotateY( ' +
            quartzIrisCarouselTheta.toString() +
            'deg )'
      );
   jQuery( Drupal.settings.quartzIris.portfolioCarousel.carouselClass ).
      css(
         '-moz-transform',
         'translateZ( ' + 
            //Drupal.settings.quartzIris.portfolioCarousel.tiltZ.toString() +
            '0px ) rotateY( ' +
            quartzIrisCarouselTheta.toString() +
            'deg )'
      );
   jQuery( Drupal.settings.quartzIris.portfolioCarousel.carouselClass ).
      css(
         '-webkit-transform',
         'translateZ( ' + 
            //Drupal.settings.quartzIris.portfolioCarousel.tiltZ.toString() +
            '0px ) rotateY( ' +
            quartzIrisCarouselTheta.toString() +
            'deg )'
      );

   return false;
}

function has3d() {
    var el = document.createElement('p'), 
        has3d,
        transforms = {
            'webkitTransform':'-webkit-transform',
            'OTransform':'-o-transform',
            'msTransform':'-ms-transform',
            'MozTransform':'-moz-transform',
            'transform':'transform'
        };

    // Add it to the body to get the computed style.
    document.body.insertBefore(el, null);

    for (var t in transforms) {
        if (el.style[t] !== undefined) {
            el.style[t] = "translate3d(1px,1px,1px)";
            has3d = window.getComputedStyle(el).getPropertyValue(transforms[t]);
        }
    }

    document.body.removeChild(el);

    return (has3d !== undefined && has3d.length > 0 && has3d !== "none");
}

